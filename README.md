# XCP Master for LINUX
This project is forked from the XCP repository of # [bdoin](https://github.com/bdoin) / **[XCP](https://github.com/bdoin/XCP)**.
The QT part of the source library was discarded and converted to a LINUX library based on make including a simple C++ example how to perform XCP as Master on a LINUX system via Ethernet.

# How to handle the LINUX implementation

## XCP library
### build
    make

### rebuild
    make clean all

## compile example
    g++ -IXCPLib xcpd.cpp build/Debug/libXCP.so -o xcpd

## execute with so
    env LD_LIBRARY_PATH=build/Debug ./xcpd


# Features, Limitations, Packets, TODO + Examples
Take a look into the origin repository, here: [robotjatek](https://github.com/robotjatek) / **[XCP](https://github.com/robotjatek/XCP)**


