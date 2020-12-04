#!/bin/bash
set -e
p=$1

if [ -e $p.c ]
then
    gcc -std=c99 $p.c && ./a.out < $p\_in.txt
    if [ -e $p\_in.txt ]
    then
        gcc -std=c99 $p.c && ./a.out < $p\_in.txt
    else
        gcc -std=c99 $p.c && ./a.out
    fi

elif [ -e $p.cpp ]
then
    if [ -e $p\_in.txt ]
    then
        g++ -std=c++14 $p.cpp && ./a.out < $p\_in.txt
    else
        g++ -std=c++14 $p.cpp && ./a.out
    fi
else
    exit
fi
