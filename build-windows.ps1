
rmdir /s /q build

mkdir build

cmake . -G "Visual Studio 17 2022" -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="conan_provider.cmake" -DCMAKE_BUILD_TYPE=Debug -B build

cd build

cmake --build .

cd ..
