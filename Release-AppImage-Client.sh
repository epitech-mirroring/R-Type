#!/bin/bash

# Set variables
APP_NAME="R-Type-Reborn-Client"
APP_VERSION="0.1.0"
BUILD_DIR="build"
APPDIR="AppImage-Release-Client"
DESKTOP_FILE="${APP_NAME}.desktop"
ICON_FILE="./icon.png"
ICON_NAME="${ICON_FILE%%.*}"
EXECUTABLE_CLIENT="r-type_client"
LINUXDEPLOY_URL="https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage"

# Prepare AppDir structure
echo "Setting up AppDir structure..."
mkdir -p "${APPDIR}/usr/bin"
mkdir -p "${APPDIR}/usr/share/icons/hicolor/256x256/apps"
mkdir -p "${APPDIR}/usr/share/applications"

# Copy the built executable
cp "${EXECUTABLE_CLIENT}" "${APPDIR}/usr/bin/"

# Copy assets if applicable
if [ -d "assets" ]; then
    cp -r assets "${APPDIR}/usr/bin/"
fi

# Create a wrapper script to set the working directory and launch the executable
echo "Creating wrapper script..."
cat > "${APPDIR}/usr/bin/start.sh" <<EOF
#!/bin/bash
# Navigate to the directory containing the executable
cd "\$(dirname "\$0")" || exit 1
cd usr/bin || exit 1
echo "Current directory: \$(pwd)"
ls
# Run the application
./${EXECUTABLE_CLIENT}
EOF

# Make the wrapper script executable
chmod +x "${APPDIR}/usr/bin/start.sh"

# Create .desktop file with the wrapper script as the entry point
echo "Creating .desktop file..."
cat > "${APPDIR}/usr/share/applications/${DESKTOP_FILE}" <<EOF
[Desktop Entry]
Type=Application
Name=${APP_NAME}
Exec=start.sh
Icon=icon
Categories=Game;
EOF

# Copy icon
if [ -f "$ICON_FILE" ]; then
    cp "$ICON_FILE" "${APPDIR}/usr/share/icons/hicolor/256x256/apps/icon.png"
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
export NO_STRIP=true
./linuxdeploy-x86_64.AppImage --appdir "$APPDIR" --output appimage || { echo "AppImage packaging failed"; exit 1; }

echo "AppImage created successfully: ${APP_NAME}-${APP_VERSION}-Client-x86_64.AppImage"
