#!/usr/bin/env bash
find examples/ -iname *.h -o -iname *.cpp | xargs clang-format -i
find lib/ -iname *.h -o -iname *.cpp | xargs clang-format -i
find tests/ -iname *.h -o -iname *.cpp | xargs clang-format -i

# Test cases for files
# Test case 1: No files exist in examples/ directory
# Expected output: No output
# Test case 2: File with .h extension exists in examples/ directory
# File path: examples/foo.h
# File content:
#     struct Foo {
#         int x;
#         int y;
#     };
# Expected output: foo.h should be formatted by clang-format
# Test case 3: File with .cpp extension exists in lib/ directory
# File path: lib/bar.cpp
# File content:
#     #include <iostream>
#
#     int main() {
#         std::cout << "Hello, world!" << std::endl;
#         return 0;
#     }
# Expected output: bar.cpp should be formatted by clang-format
# Test case 4: Files with .h and .cpp extensions exist in tests/ directory
# File paths: tests/baz.h, tests/baz.cpp
# File contents:
#     baz.h:
#         #ifndef BAZ_H
#         #define BAZ_H
#
#         void baz();
#
#         #endif  // BAZ_H
#
#     baz.cpp:
#         #include "baz.h"
#
#         void baz() {
#             // Function implementation
#         }
# Expected output: baz.h and baz.cpp should be formatted by clang-format