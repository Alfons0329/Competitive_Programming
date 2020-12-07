#!/bin/bash
set -e
p=$1
asan="-fsanitize=address"

if [ -e $p.c ]
then
    if [ -e $p\_in.txt ]
    then
        gcc -std=c99 $p.c $asan && ./a.out < $p\_in.txt > out\_$p.txt
    else
        gcc -std=c99 $p.c $asan && ./a.out > out\_$p.txt
    fi

elif [ -e $p.cpp ]
then
    if [ -e $p\_in.txt ]
    then
        g++ -std=c++14 $p.cpp $asan && ./a.out < $p\_in.txt > out\_$p.txt
    else
        g++ -std=c++14 $p.cpp $asan && ./a.out > out\_$p.txt
    fi
else
    exit
fi
