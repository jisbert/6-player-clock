#!/bin/bash

# Bash script to run cpplint on every project file
# Based on https://stackoverflow.com/a/31308870
#
# Usage
# -----
#
# $ chmod +x cpplint.sh
# $ ./cpplint.sh

cpplint --counting=detailed $( find . -name \*.h -or -name \*.cc | grep -vE "^\.\/(build|coverage)\/" )
