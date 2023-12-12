#!/usr/bin/env bash
function example_code() {
    find examples/ -iname *.h -o -iname *.cpp | xargs clang-format -i
    find lib/ -iname *.h -o -iname *.cpp | xargs clang-format -i
    find tests/ -iname *.h -o -iname *.cpp | xargs clang-format -i
}
example_code