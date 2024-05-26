# C++ Gameboy Emulator

A practice project to understand more about various computer science concepts and C++ by developing a Gameboy Emulator.


## How to Build

Configure CMake

```bash
cmake -S . -B build
```

Build the project

```bash
cmake --build build
```

Run the built code

```bash
build/src/gameboy
```


### Helpful Notes

1. How to output readable assembly with hex on Mac

```bash
hexdump -e \"%07_ax\ \"\ 16/1\ \"\ %02x\"\ \"\\n\" <file>
```

2. The Game Boy is little endian which means that when you have numbers that are larger than 1 byte.  This is mostly only important for stores and loads.