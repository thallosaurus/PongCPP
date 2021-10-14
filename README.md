# PongCPP

## Build

Run ```mkdir build/; cmake .; cmake --build . --config <Debug/Release>```

To execute it, run ```./PongCPP```

- Open VSCode
- Press Ctrl + Shift + P
- Run Following tasks in this order:
    - CMake: Build Cache
    - CMake: Build

if you want to quickly clean the repository, run task "Git: restore repository"

## Running on Raspberry Pi
Run the following Commands to setup a working environment
```
sudo apt install cmake
mkdir build
cd build
cmake ..
make
```