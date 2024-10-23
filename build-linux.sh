#!/bin/bash

# Set script to exit on any errors.
set -e

# Variables for dependency directories
BUILD_DIR="build"
CONAN_PROFILE="default"

# Function to print info messages in yellow color
info() {
  echo -e "\033[1;33m[info] $1\033[0m"
}

# Step 1: Install Conan if not already installed
info "Checking if Conan is installed..."
if ! command -v conan &> /dev/null
then
    info "Conan not found, installing Conan..."
    pip install conan
fi

# Step 2: Create build directory if it does not exist
info "Creating build directory if it does not exist..."
if [ ! -d "$BUILD_DIR" ]; then
  info "Creating build directory..."
  mkdir -p "$BUILD_DIR"
fi

# Step 3: Run Conan to install missing dependencies
info "Changing to build directory..."
cd "$BUILD_DIR"

info "Ensuring Conan profile is available..."
if ! conan profile list | grep -q "$CONAN_PROFILE"; then
    info "Creating Conan profile: $CONAN_PROFILE"
    conan profile detect --name "$CONAN_PROFILE"
fi

info "Installing dependencies with Conan..."
conan install .. --build=missing --profile="$CONAN_PROFILE" -g CMakeDeps -g CMakeToolchain

# Step 4: Run CMake to configure the build
info "Running CMake to configure the build..."
cmake -S .. -B . -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_PREFIX_PATH="." -DCMAKE_BUILD_TYPE=Release

# Step 5: Build the project with CMake
info "Building the project with CMake..."
cmake --build . --target r-type_server

# Step 5: Build the project with CMake
info "Building the project with CMake..."
cmake --build . --target r-type_client
