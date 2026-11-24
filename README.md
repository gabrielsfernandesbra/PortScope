# PortScope

A lightweight TCP port scanner written in C.

## Installation

### Windows

Compile using GCC (MinGW):

```bash
gcc main.c -o scanner.exe -lws2_32
```

## Usage

### IPv4

```bash
.\scanner.exe <IP_ADDRESS>
```

Example:

```bash
.\scanner.exe 192.168.0.1
```

## Features

- TCP port scanning
- IPv4 support
- Written in C
- Windows support

## License

This project is licensed under the MIT License.

Copyright (c) 2026 Gabriel S Fernandes
