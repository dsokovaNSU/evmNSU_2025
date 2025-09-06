#!/bin/bash

#n=$1
echo "n = 2000000000 ~ 15 seconds"
echo -e "\n4.1 Утилита time"
g++ -O2 lab1_time.cpp -o 4_1.out -Wall -Wextra -Werror
time ./4_1.out # <<< "$n"

echo -e "\n4.2 Библиотечная функция clock_gettime"
g++ -O2 lab1_clock_gettime.cpp -o 4_2.out -lrt -Wall -Wextra -Werror
./4_2.out #<<< "$n"

echo -e "\n4.3 Библиотечная функция time"
g++ -O2 lab1_libtime.cpp -o 4_3.out -Wall -Wextra -Werror
./4_3.out #<<< "$n"

echo -e "\n4.4 Машинная команда rdtsc" 
g++ -O2 lab1_rdtsc.cpp -o 4_4.out -Wall -Wextra -Werror
./4_4.out #<<< "$n"

rm 4_1.out 4_2.out 4_3.out 4_4.out
