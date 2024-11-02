#!/bin/bash

# Set script to exit on any errors.
set -e

# Variables for dependency directories
BUILD_DIR="build"
CONAN_PROFILE="default"

#Get the os type
os=$(uname -a)

#Choose the package manager based on the os type
if [[ $os == *"debian"* ]]; then
  package_manager="apt-get"
elif [[ $os == *"fedora"* ]]; then
  package_manager="dnf"
elif [[ $os == *"CentOS"* ]]; then
  package_manager="yum"
elif [[ $os == *"Darwin"* ]]; then
  package_manager="brew"
else
  echo "Unsupported OS"
  exit 1
fi

# Function to print info messages in yellow color
info() {
  echo -e "\033[1;33m[info] $1\033[0m"
}

# Step: Check if python is installed
info "Checking if python is installed..."
if ! command -v python &> /dev/null
then
    info "Python not found, installing Python..."
    sudo $package_manager install -y python
fi
info "Python is installed."

# Step: Check if pip is installed
info "Checking if pip is installed..."
if ! command -v pip &> /dev/null
then
    info "Pip not found, installing Pip..."
    sudo $package_manager install -y python-pip
fi
info "Pip is installed."

# Install Conan if not already installed
info "Checking if Conan is installed..."
if ! command -v conan &> /dev/null
then
    info "Conan not found, installing Conan..."
    sudo $package_manager install -y conan
fi

# Install CMake if not already installed
info "Checking if CMake is installed..."
if ! command -v cmake &> /dev/null
then
    info "CMake not found, installing CMake..."
    sudo $package_manager install -y cmake
fi

# Install Ninja if not already installed
info "Checking if Ninja is installed..."
if ! command -v ninja &> /dev/null
then
    info "Ninja not found, installing Ninja..."
    sudo $package_manager install -y ninja-build
fi

# Install C++ compiler if not already installed
info "Checking if C++ compiler is installed..."
if ! command -v g++ &> /dev/null
then
    info "C++ compiler not found, installing C++ compiler..."
    sudo $package_manager install -y gcc-c++
fi

# Step: Create build directory if it does not exist
info "Creating build directory if it does not exist..."
if [ ! -d "$BUILD_DIR" ]; then
  info "Creating build directory..."
  mkdir -p "$BUILD_DIR"
fi

info "Ensuring Conan profile is available..."
if ! conan profile list | grep -q "$CONAN_PROFILE"; then
    info "Creating Conan profile: $CONAN_PROFILE"
    conan profile detect --name "$CONAN_PROFILE"
fi

info "Adding remote for Conan..."
conan remote add --force Epitech-Mirroring https://nexus.place2die.com/repository/Epitech-Mirroring/

info "Installing dependencies with Conan..."
sudo conan install . --output-folder="build" --build=missing -s:a build_type=Release --profile="$CONAN_PROFILE" -g CMakeDeps -g CMakeToolchain -c tools.system.package_manager:mode=install

# Step: Run CMake to configure the build
info "Running CMake to configure the build..."
cmake -B ./build -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake" -DCMAKE_PREFIX_PATH="build" -DCMAKE_BUILD_TYPE=Release

# Step: Detect number of available threads for parallel build
NUM_THREADS=$(nproc --all)
info "Number of threads available for build: $NUM_THREADS"

# Step: Build the project with CMake
info "Building the server project with CMake..."
cmake --build . --target r-type_server -- -j "$NUM_THREADS"

info "Building the client project with CMake..."
cmake --build . --target r-type_client -- -j "$NUM_THREADS"
