#!/bin/bash

cd "${0%/*}"

# run the app
./PCem

# ignore default segfault 11
exit 0
