#!/bin/sh
printf "Running medium map as player 2 - X\n"
printf "===========================================\n"
printf "Against abanlin\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 players/abanlin.filler -p2 .././filler 2>&1 | grep "=="
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against carli\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 players/carli.filler 2 -p2 .././filler 2>&1 | grep "=="
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against champely\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 players/champely.filler -p2 .././filler 2>&1 | grep "=="
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against grati\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 players/grati.filler 2 -p2 .././filler 2>&1 | grep "=="
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against hcao\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 players/hcao.filler -p2 .././filler 2>&1 | grep "=="
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against superjeannot\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 players/superjeannot.filler -p2 .././filler 2>&1 | grep "=="
	n=$(( n+1 ))
done
printf "===========================================\n"