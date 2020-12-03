#!/bin/bash
set -e
p=$1

if [ -e $p.c ]
then
    gcc -std=c99 $p.c && ./a.out < $p\_in.txt
elif [ -e $p.cpp ]
then
    g++ -std=c+=14 $p.cpp && ./a.out < $p\_in.txt
else
    exit
fi
