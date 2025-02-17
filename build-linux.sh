#!/bin/bash

# Set script to exit on any errors.
set -e

# Variables for dependency directories
BUILD_DIR="build"
CONAN_PROFILE="default"

# Check if the script is run as root
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root. Please run with sudo or as root user."
   exit 1
fi

#Get the os type
os=$(uname -a)
os_type=""

#Choose the package manager based on the os type
if [[ $os == *"debian"* ]]; then
  package_manager="apt-get"
  os_type="debian"
elif [[ $os == *"fedora"* ]]; then
  package_manager="dnf"
  os_type="fedora"
else
  echo "Unsupported OS. Please choose your OS type (1=fedora, 2=debian):"
  read os_choice
  if [[ $os_choice == "1" ]]; then
    os_type="fedora"
  elif [[ $os_choice == "2" ]]; then
      os_type="debian"
  else
    echo "Invalid choice. Exiting."
    exit 1
  fi
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
    $package_manager install -y python
    if [ $os_type == "debian" ]; then
        $package_manager install -y python3-full
    fi
fi
info "Python is installed."

# Step: Check if pip is installed
info "Checking if pip is installed..."
if ! command -v pip &> /dev/null
then
    info "Pip not found, installing Pip..."
    $package_manager install -y python-pip
    if [ $os_type == "debian" ]; then
        $package_manager install -y python3-pip
    fi
fi
info "Pip is installed."

# for debian based systems check if pkg-config is installed
if [ $os_type == "debian" ]; then
    info "Checking if pkg-config is installed..."
    if ! command -v pkg-config &> /dev/null
    then
        info "Pkg-config not found, installing Pkg-config..."
        $package_manager install -y pkg-config
    fi
fi

# for fedora based systems check if build-essential is installed
if [ $os_type == "fedora" ]; then
    info "Checking if build-essential is installed..."
    dnf install -y libstdc++-static
    dnf install -y make automake gcc gcc-c++ kernel-devel
fi

# for debian based systems check if build-essential is installed
if [ $os_type == "debian" ]; then
    info "Checking if build-essential is installed..."
    if ! command -v build-essential &> /dev/null
    then
        info "Build-essential not found, installing Build-essential..."
        $package_manager install -y build-essential
    fi
fi

# Install Conan if not already installed
info "Checking if Conan is installed..."
if ! command -v conan &> /dev/null
then
    info "Conan not found, installing Conan..."
    if [ $os_type == "fedora" ]; then
        pip install conan
    fi
    if [ $os_type == "debian" ]; then
        pip install conan --break-system-packages
    fi
fi

# Install CMake if not already installed
info "Checking if CMake is installed..."
if ! command -v cmake &> /dev/null
then
    info "CMake not found, installing CMake..."
    $package_manager install -y cmake
fi

# Install Ninja if not already installed
info "Checking if Ninja is installed..."
if ! command -v ninja &> /dev/null
then
    info "Ninja not found, installing Ninja..."
    $package_manager install -y ninja-build
fi

# Install C++ compiler if not already installed
info "Checking if C++ compiler is installed..."
if ! command -v g++ &> /dev/null
then
    info "C++ compiler not found, installing C++ compiler..."
    $package_manager install -y gcc-c++
fi

# Step: Create build directory if it does not exist
info "Creating build directory if it does not exist..."
if [ ! -d "$BUILD_DIR" ]; then
  info "Creating build directory..."
  mkdir -p "$BUILD_DIR"
fi

#Remove conan lib cache for stellar-forge
info "Removing Conan cache for stellar-forge..."
conan remove 'stellar-forge*' -c

# Step: make profile default
info "Ensuring Conan profile is available..."
conan profile detect --force

info "Adding remote for Conan..."
conan remote add --force Epitech-Mirroring https://nexus.place2die.com/repository/Epitech-Mirroring/

info "Installing dependencies with Conan..."
conan install . --output-folder="build" --build=missing -s:a build_type=Release -c tools.system.package_manager:mode=install

# Step: Run CMake to configure the build
info "Running CMake to configure the build..."
cmake -B ./$BUILD_DIR -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake" -DCMAKE_PREFIX_PATH="$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release

# Step: Detect number of available threads for parallel build
NUM_THREADS=$(nproc --all)
info "Number of threads available for build: $NUM_THREADS"

# Step: Build the project with CMake
info "Building the server project with CMake..."
cmake --build ./$BUILD_DIR --target r-type_server -- -j "$NUM_THREADS"

info "Building the client project with CMake..."
cmake --build ./$BUILD_DIR --target r-type_client -- -j "$NUM_THREADS"

# Step: copy the binaries to the root directory
info "Copying the binaries to the root directory..."
cp ./$BUILD_DIR/server/r-type_server ./r-type_server
cp ./$BUILD_DIR/client/r-type_client ./r-type_client
