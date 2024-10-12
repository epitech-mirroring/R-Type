
# Installing `Conan`

This guide provides step-by-step instructions to install `Conan` on Windows, Linux, and macOS, including how to configure your system for use.

## Windows / Windows server

1. **Open PowerShell as Administrator**.
2. **Install Conan using `pip`**:
    - First, ensure that you have Python and `pip` installed. If not, download and install Python from the [official website](https://www.python.org/downloads/).
    - Run the following command to install Conan:
      ```bash
      pip install conan
      ```

3. **Verify installation**:
   After installing, verify Conan is installed by running:
   ```bash
   conan --version
   ```

4. **Add Conan to the system path** (optional):
   If you encounter issues with the `conan` command, you may need to add Python's Scripts folder to your system path:
    - Open **Start** and search for **Environment Variables**.
    - In the System Properties window, click on **Environment Variables**.
    - Under **System variables**, find and select the **Path** variable, then click **Edit**.
    - Click **New** and add the path to Python’s Scripts folder, typically `C:\Users\YourUsername\AppData\Local\Programs\Python\PythonXX\Scripts`.
    - Click **OK** to close all windows.

## Linux

1. **Open a terminal**.
2. **Install Conan using `pip`**:
   First, make sure you have Python and `pip` installed. Then, install Conan:
   ```bash
   sudo apt update
   sudo apt install python3-pip
   pip3 install conan
   ```

3. **Add Conan to the system path** (if necessary):
    - If `conan` is not recognized, ensure `~/.local/bin` is in your PATH by adding the following line to your `.bashrc` or `.zshrc` file:
      ```bash
      export PATH="$HOME/.local/bin:$PATH"
      ```
    - Apply the changes:
      ```bash
      source ~/.bashrc
      ```

4. **Verify installation**:
   Restart your terminal and run:
   ```bash
   conan --version
   ```

## macOS

1. **Open a terminal**.
2. **Install Homebrew** (if not already installed):
    - Homebrew is a package manager for macOS. You can install it with:
      ```bash
      /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
      ```

3. **Install Conan using Homebrew**:
    - Once Homebrew is installed, install Conan with:
      ```bash
      brew install conan
      ```

4. **Verify installation**:
   Restart your terminal and run:
   ```bash
   conan --version
   ```

---

Follow these instructions to ensure a smooth installation of `Conan` on your system.
