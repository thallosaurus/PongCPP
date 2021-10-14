#!/bin/sh
g++ $(ls *.cpp) -lpthread -o main && ./main