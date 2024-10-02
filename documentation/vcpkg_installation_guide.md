
# Installing `vcpkg` (outdated guide conan is used now)

This guide provides step-by-step instructions to install `vcpkg` on Windows, Linux, and macOS, including how to add it to your system path.

## Windows / Windows server

1. **Open PowerShell as Administrator**.
2. **Clone the `vcpkg` repository**:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
   ```

3. **Add `vcpkg` to the system path**:
   - Open **Start** and search for **Environment Variables**.
   - In the System Properties window, click on **Environment Variables**.
   - Under **System variables**, find and select the **Path** variable, then click **Edit**.
   - Click **New** and add the full path to the `vcpkg` executable, e.g., `C:\path\to\vcpkg`.
   - Click **OK** to close all windows.

<img src="https://cdn.discordapp.com/attachments/539130489798393858/1289630502382342174/image.png?ex=66f9857f&is=66f833ff&hm=024db2fbffb9cfa002e2b95080f0e224ba9e029ef974dbbac3313d3fb7a31962&" width="800px" />
<br>
<img src="https://cdn.discordapp.com/attachments/539130489798393858/1289630725884084324/image.png?ex=66f985b5&is=66f83435&hm=b35ad6528588045461e476441abfd3bb57750922471fd3ff6d347e01de6adf08&" width="400px" />

4. **Verify installation**:
   After adding `vcpkg` to the path, restart your terminal or PowerShell and run:
   ```bash
   vcpkg --version
   ```

## Linux

1. **Open a terminal**.
2. **Install essential build tools**:
   ```bash
   sudo apt-get update
   sudo apt-get install build-essential curl zip unzip
   ```

3. **Clone the `vcpkg` repository**:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh
   ```

4. **Add `vcpkg` to the system path**:
   - Open your `.bashrc` or `.zshrc` file:
     ```bash
     nano ~/.bashrc
     ```
   - Add the following line at the end:
     ```bash
     export PATH="$HOME/path/to/vcpkg:$PATH"
     ```
   - Save and exit the editor, then run:
     ```bash
     source ~/.bashrc
     ```

5. **Verify installation**:
   Restart your terminal and run:
   ```bash
   vcpkg --version
   ```

## macOS

1. **Open a terminal**.
2. **Install Xcode Command Line Tools**:
   ```bash
   xcode-select --install
   ```

3. **Clone the `vcpkg` repository**:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh
   ```

4. **Add `vcpkg` to the system path**:
   - Open your `.bash_profile` or `.zshrc` file:
     ```bash
     nano ~/.bash_profile
     ```
   - Add the following line:
     ```bash
     export PATH="$HOME/path/to/vcpkg:$PATH"
     ```
   - Save and exit, then run:
     ```bash
     source ~/.bash_profile
     ```

5. **Verify installation**:
   Restart your terminal and run:
   ```bash
   vcpkg --version
   ```

---

Follow these instructions to ensure a smooth installation of `vcpkg` on your system.
