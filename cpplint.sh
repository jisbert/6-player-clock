#!/bin/bash

# Bash script to run cpplint on every project file
# Based on https://stackoverflow.com/a/31308870
#
# Usage
# -----
#
# $ chmod +x cpplint.sh
# $ ./cpplint.sh

cpplint --counting=detailed ./include/button/button_controller.h ./include/button/button_event.h ./include/button/button_handler.h ./include/buzzer/buzzer.h ./src/app.cc ./src/button/button_controller.cc ./src/button/button_event.cc ./src/button/button_handler.cc ./src/buzzer/buzzer.cc ./tests/mocks/include/button/button_handler_mock.h ./tests/mocks/src/button/button_handler_mock.cc ./tests/src/button/button_controller_tests.cc ./tests/src/button/button_handler_tests.cc ./tests/src/buzzer/buzzer_tests.cc ./tests/src/tests_app.cc
