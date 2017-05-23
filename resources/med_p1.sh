#!/bin/sh
printf "Running medium map as player 1 - O\n"
printf "===========================================\n"
printf "Against abanlin\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 .././filler -p2 players/abanlin.filler 2>&1 | grep "=="
	cat filler.trace | grep "won"
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against carli\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 .././filler -p2 players/carli.filler 2>&1 | grep "=="
	cat filler.trace | grep "won"
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against grati\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 .././filler -p2 players/grati.filler 2>&1 | grep "=="
	cat filler.trace | grep "won"
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against hcao\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 .././filler -p2 players/hcao.filler 2>&1 | grep "=="
	cat filler.trace | grep "won"
	n=$(( n+1 ))
done
printf "===========================================\n"
printf "Against superjeannot\n"
n=1
while [ $n -le 10 ]
do
	printf "\nTest number $n\n"
	./filler_vm -f maps/map01 -p1 .././filler -p2 players/superjeannot.filler 2>&1 | grep "=="
	cat filler.trace | grep "won"
	n=$(( n+1 ))
done
printf "===========================================\n"
