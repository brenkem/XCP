# XCP Master for LINUX
This project is forked from the XCP repository of [bdoin](https://github.com/bdoin) / **[XCP](https://github.com/bdoin/XCP)**.
The QT part of the source library was discarded and converted to a LINUX library based on make including a simple C++ example how to perform XCP as Master on a LINUX system via Ethernet.

# How to handle the LINUX implementation

## XCP library
### build
    make

### rebuild
    make clean all

## SeedNKey shared object
### build
    cd SeednKey-Template
    make

## XCP Master Example
### compile
    g++ -IXCPLib xcpd.cpp build/Debug/libXCP.so -ldl -o xcpd

### execute with library
    env LD_LIBRARY_PATH=build/Debug ./xcpd

# Features, Limitations, Packets, TODO + Examples
Take a look into the origin repository, here: [robotjatek](https://github.com/robotjatek) / **[XCP](https://github.com/robotjatek/XCP)**


