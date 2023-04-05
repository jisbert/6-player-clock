cd build
lcov -d . -b tests -z
tests/tests.exe
lcov -d . -b tests -c -o coverage.info
genhtml --demangle-cpp -o coverage coverage.info