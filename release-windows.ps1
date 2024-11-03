function Write-Info {
    param([string]$message)
    Write-Host "[Info] $message" -ForegroundColor Yellow
}

Write-Info "Cpacking the project..."
cd build
cpack
cd ..

# Copy the installer to the root directory
Write-Info "Copying the installer to the root directory..."
Copy-Item -Path ".\build\*.exe" -Destination "." -Force
