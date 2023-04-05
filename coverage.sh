lcov -d build/tests -z
build/tests/tests.exe
lcov -d build/tests -c -o build/coverage/coverage.info
genhtml build/coverage/coverage.info -o build/coverage