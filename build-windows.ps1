rmdir /s /q build


# Run Conan to install dependencies with C++17 and Release settings
conan install . --output-folder="build" --build=missing -s build_type=Release -s compiler.cppstd=17

# Configure the CMake project with the Conan toolchain and prefix paths
cmake -B build -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake" -DCMAKE_PREFIX_PATH="build"

# Build the project in Release mode
cmake --build build --config Release
