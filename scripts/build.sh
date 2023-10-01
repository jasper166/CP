#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ -static -DLOCAL -lm -s -x c++ -Wall -Wextra -O2 -std=c++17 -o $1 $1.cpp 
exit 0