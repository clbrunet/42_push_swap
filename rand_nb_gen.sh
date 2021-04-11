#!/bin/bash

if [ $# -eq 0 ]; then
	n=10
	mod=0
elif [ $# -eq 1 ]; then
	n=$1
	mod=0
elif [ $# -eq 2 ]; then
	n=$1
	mod=$2
	if [ $mod -lt $n ]; then
		echo "Second parameter ($2) cannot be less than the first ($1)."
		exit
	fi
else
	exit
fi

i=0
while [ $i -lt $n ]; do
	if [ $mod -eq 0 ]; then
		new=$RANDOM
	else
		new=$(($RANDOM % $mod))
	fi
	for random in ${randoms[@]}; do
		if [ $new -eq $random ]; then
			continue 2
		fi
	done
	echo -n $new
	randoms+=( $new )
	i=$[$i+1]
	if [ ! $i -eq $n ]; then
		echo -n " "
	fi
done
