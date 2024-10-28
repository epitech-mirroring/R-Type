function Write-Info {
    param([string]$message)
    Write-Host "[Info] $message" -ForegroundColor Yellow
}

# Check if Chocolatey is installed, if not, install it with elevated privileges
Write-Info "Checking if Chocolatey is installed..."
if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
    Write-Info "Chocolatey not found. Installing Chocolatey with elevated privileges..."
    Start-Process powershell -Verb runAs -Wait -ArgumentList {
        Set-ExecutionPolicy Bypass -Scope Process -Force;
        [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072;
        iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
    }
    # Update the PATH environment variable for the current session to include Chocolatey
    $env:Path += ";$([System.Environment]::GetEnvironmentVariable('ChocolateyInstall'))\bin"
    Write-Info "Chocolatey installed and PATH updated."
}

# Install Conan, CMake, Ninja, and Visual Studio 2022 Build Tools if not already installed
Write-Info "Checking if Conan is installed..."
if (-not (Get-Command conan -ErrorAction SilentlyContinue)) {
    Write-Info "Conan not found. Installing Conan..."
    Start-Process powershell -Verb runAs -ArgumentList { choco install conan -y } -Wait
    $env:Path += ";$([System.Environment]::GetEnvironmentVariable('Path', [System.EnvironmentVariableTarget]::User))"
    Write-Info "Conan installed and PATH updated."
}

Write-Info "Checking if CMake is installed..."
if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Info "CMake not found. Installing CMake..."
    Start-Process powershell -Verb runAs -ArgumentList { choco install cmake -y } -Wait
    $env:Path += ";$([System.Environment]::GetEnvironmentVariable('Path', [System.EnvironmentVariableTarget]::Machine))"
    Write-Info "CMake installed and PATH updated."
}

Write-Info "Checking if Python (pip) is installed..."
if (-not (Get-Command pip -ErrorAction SilentlyContinue)) {
    Write-Info "Python not found. Installing Python..."
    Start-Process powershell -Verb runAs -ArgumentList { choco install python -y } -Wait
    $env:Path += ";$([System.Environment]::GetEnvironmentVariable('Path', [System.EnvironmentVariableTarget]::Machine))"
    Write-Info "Python installed and PATH updated."
}

# Install Visual Studio 2022 Build Tools if not already installed
Write-Info "Checking if Visual Studio 2022 Build Tools are installed..."
$vsPath1 = "C:\Program Files (x86)\Microsoft Visual Studio\2022"
$vsPath2 = "C:\Program Files\Microsoft Visual Studio\2022"
if (-not (Test-Path $vsPath1) -and -not (Test-Path $vsPath2)) {
    Write-Info "Visual Studio Build Tools not found. Installing via winget..."
    winget install -e --id Microsoft.VisualStudio.2022.BuildTools --override "--passive --wait --add Microsoft.VisualStudio.Workload.VCTools;includeRecommended"
    Write-Info "Visual Studio Build Tools installed."
}

# Setup Visual Studio Environment Variables
$vsvarsPath = "C:\Program Files\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat"
if (Test-Path $vsvarsPath) {
    Write-Info "Setting up Visual Studio environment variables..."
    & cmd.exe /c "`"$vsvarsPath`" x64"
}

# Remove 'build' directory if it exists, then recreate it
$buildDir = "build"
Write-Info "Preparing the build directory..."
if (Test-Path $buildDir) {
    Write-Info "Removing existing 'build' directory..."
    Remove-Item -Recurse -Force $buildDir
}
New-Item -ItemType Directory -Path $buildDir
Write-Info "'build' directory created."

# Run conan profile detect --force to ensure the profile exists
Write-Info "Running 'conan profile detect --force'..."
conan profile detect --force

# Run Conan to install dependencies with C++17 and Release settings
Write-Info "Installing Conan dependencies with C++17 and Release settings..."
conan install . --output-folder="build" --build=missing -s build_type=Release -s:a compiler.cppstd=17

# Configure the CMake project with the Conan toolchain and prefix paths
Write-Info "Configuring the CMake project..."
cmake -B build -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake" -DCMAKE_PREFIX_PATH="build"

# Build the project in Release mode
Write-Info "Building the project in Release mode..."
cmake --build build --config Release
Write-Info "Build completed successfully."
