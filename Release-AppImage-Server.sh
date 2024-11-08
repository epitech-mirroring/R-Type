#!/bin/bash

# Set variables
APP_NAME="R-Type-Reborn-Server"
APP_VERSION="0.1.0"
BUILD_DIR="build"
APPDIR="AppImage-Release-Server"
DESKTOP_FILE="${APP_NAME}.desktop"
ICON_FILE="./icon.png"
ICON_NAME="${ICON_FILE%%.*}"
EXECUTABLE_SERVER="r-type_server"
LINUXDEPLOY_URL="https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage"

# Prepare AppDir structure
echo "Setting up AppDir structure..."
mkdir -p "${APPDIR}/usr/bin"
mkdir -p "${APPDIR}/usr/share/icons"
mkdir -p "${APPDIR}/usr/share/applications"

# Copy the built executables
cp "${EXECUTABLE_SERVER}" "${APPDIR}/usr/bin/"

# Create .desktop file
echo "Creating .desktop file..."
cat > "${APPDIR}/usr/share/applications/${DESKTOP_FILE}" <<EOF
[Desktop Entry]
Type=Application
Name=${APP_NAME}
Exec=${EXECUTABLE_SERVER}
Icon=icon
Categories=Game;
EOF

# Copy icon
if [ -f "$ICON_FILE" ]; then
    cp "$ICON_FILE" "${APPDIR}/usr/share/icons/hicolor/256x256/apps/${ICON_FILE}"
else
    echo "Icon file $ICON_FILE not found!"
    exit 1
fi

# Download linuxdeploy if not already present
if [ ! -f "linuxdeploy-x86_64.AppImage" ]; then
    echo "Downloading linuxdeploy..."
    wget "$LINUXDEPLOY_URL" -O linuxdeploy-x86_64.AppImage
    chmod +x linuxdeploy-x86_64.AppImage
fi

# Package the AppImage without stripping
echo "Packaging the AppImage..."
# Set STRIP environment variable to true to disable stripping
export NO_STRIP=true
./linuxdeploy-x86_64.AppImage --appdir "$APPDIR" --output appimage || { echo "AppImage packaging failed"; exit 1; }

echo "AppImage created successfully: ${APP_NAME}-${APP_VERSION}-Server-x86_64.AppImage"
