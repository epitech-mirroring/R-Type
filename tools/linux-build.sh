rm -f *.exe
rm -rf cmake-build/

mkdir cmake-build

cmake . -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="conan_provider.cmake" -DCMAKE_BUILD_TYPE=Debug -B cmake-build

cd cmake-build

make -j 10

cd ..
