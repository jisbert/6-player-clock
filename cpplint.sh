#!/bin/bash

# Bash script to run cpplint on every project file
# Based on https://stackoverflow.com/a/31308870
#
# Usage
# -----
#
# $ chmod +x cpplint.sh
# $ ./cpplint.sh

find . -type d \( -path ./build -or -path ./coverage \) -prune -or \( -name \*.h -or -name \*.cc \) -execdir cpplint --counting=detailed \{\} +
