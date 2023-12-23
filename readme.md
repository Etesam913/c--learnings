# 🟨 c++ learnings

## Overview

### Implemented data structures

- Trie

## Creating build files

```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```

- Creates a `build` dir from the using the current dir as the `src`
- `$VCPKG_ROOT` is the path to your `/vcpkg` dir.

### ⚡️ Create & run executable

```bash
cd build/ && make && ./C++Playground
```
