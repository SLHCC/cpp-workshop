# Setup Guide for C++ Workshop

This guide explains how to get started for the SLHCC C++ workshop - in terms of setting up your environment and running C++ programs.

## Windows

### Setup Compiler

You will need to install GCC with MinGW, the instructions can be found here (ask a committee member if you get stuck): https://code.visualstudio.com/docs/cpp/config-mingw


### Setup IDE

Visual Studio Code is recommended for Windows. Download and install here: https://code.visualstudio.com/

### Running C++ Programs

**You will need to install make for Windows before running C++ programs on Windows**: https://gnuwin32.sourceforge.net/packages/make.htm#:~:text=Make%20is%20a%20tool%20which,compute%20it%20from%20other%20files.

The examples/practicals in this workshop repo contain a `Makefile` this makes it easier to run when dealing with multiple compilation units.

To run a C++ program, **make sure you are in the same directory where the Makefile is** and type: `make .` and then an executable will appear, type the name of the executable like so to run the program: `./name_of_executable.exe`

## macOS

### Setup Compiler

I recommend using `brew` as your package manager **always** on macOS.

Install brew first. Instructions can be found here: https://brew.sh/

After you have installed brew, install `gcc` which contains the `g++` C++ compiler:

- `brew update`
- `brew upgrade`
- `brew install gcc`

### Setup IDE

Visual Studio Code is recommended for Mac. Now that you have brew installed simply type the following command into a terminal:

`brew install --cask visual-studio-code`

### Running C++ Programs

The examples/practicals in this workshop repo contain a `Makefile` this makes it easier to run when dealing with multiple compilation units.

To run a C++ program, **make sure you are in the same directory where the Makefile is** and type: `make .` and then an executable will appear, type the name of the executable like so to run the program: `./name_of_executable`

## Linux

### Setup Compiler

Install `gcc` (which contains the `g++` C++ compiler):
- Ubuntu based distributions `sudo apt-get install gcc`
- Arch based distributions: `sudo pacman -S gcc`
- Fedora based distributions: `sudo dnf install gcc`

### Setup IDE

VS Codium is recommended for Linux. Installation instructions can be found here: 

https://vscodium.com/#install

### Running C++ Programs

The examples/practicals in this workshop repo contain a `Makefile` this makes it easier to run when dealing with multiple compilation units.

To run a C++ program, **make sure you are in the same directory where the Makefile is** and type: `make .` and then an executable will appear, type the name of the executable like so to run the program: `./name_of_executable`