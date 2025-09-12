#!/bin/bash

OPT_LEVEL="${1:-O1}"

for((i=2700000000;i<=5000000000;i+=230000000))
do
sync
echo "N = $i"
g++ -$OPT_LEVEL lab2_clock_gettime.cpp -o 4_2.out -Wall -Wextra -Werror
./4_2.out $i
done

rm 4_2.out      