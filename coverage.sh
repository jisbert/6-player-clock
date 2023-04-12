#!/bin/bash

# Bash script to create code coverage report on Windows MinGW64
# This cannot be accomplished using CodeCoverage cmake plugin
# cause a failure while running lcov
#
# Usage
# -----
#
# $ cmake -B coverage -DENABLE_TESTS=ON
# $ cmake --build tests --target tests
# $ chmod +x coverage.sh
# $ ./coverage.sh

cd coverage || exit
lcov -d . -b tests -z
tests/tests.exe
lcov -d . -b tests -c -o coverage.info
genhtml --demangle-cpp -o coverage coverage.info
