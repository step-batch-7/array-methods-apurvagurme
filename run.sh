#! /bin/bash

mkdir -p bin

rm -rf *.o
gcc -c *.c
gcc -o ./bin/$1 *.o
rm -rf *.o
./bin/$1