#!/bin/bash

make

if [ $# -eq 0 ]; then
	n=25
elif [ $# -eq 1 ]; then
	n=$1
else
	exit
fi

echo -e "Mean with a stack length of 100 :"
mean=0
n=$[$n+1]
i=1
while [ $i -lt $n ]; do
	output="$(ARG="$(./rand_nb_gen.sh 100)"; ./push_swap $ARG | wc -l)"
	echo "[$i] : $output"
	mean=$[$mean+$output]
	i=$[$i+1]
done
n=$[$n-1]
mean=$[$mean/$n]
echo -e "\nmean : $mean\n"

echo -e "Mean with a stack length of 500 :"
mean=0
n=$[$n+1]
i=1
while [ $i -lt $n ]; do
	output="$(ARG="$(./rand_nb_gen.sh 500)"; ./push_swap $ARG | wc -l)"
	echo "[$i] : $output"
	mean=$[$mean+$output]
	i=$[$i+1]
done
n=$[$n-1]
mean=$[$mean/$n]
echo -e "\nmean : $mean"
