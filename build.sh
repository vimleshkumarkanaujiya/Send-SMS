#!/bin/bash

# Clone the project, find CMakeLists.txt and Create a build directory.
git clone https://github.com/vimleshkumarkanaujiya/Send-SMS.git
cd Send-SMS
cmake -S . -B build

# Compile and Install the project
sudo make install
