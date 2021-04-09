#!/bin/bash

if [ $# -eq 0 ]; then
	n=10
elif [ $# -gt 1 ]; then
	exit
else
	n=$1
fi

i=0
while [ $i -lt $n ]; do
	new=$RANDOM
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
