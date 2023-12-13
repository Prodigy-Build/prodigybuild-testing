#!/usr/bin/env bash
function example {
    find examples/ -iname *.h -o -iname *.cpp | xargs clang-format -i
}

example
