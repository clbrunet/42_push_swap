#!/bin/bash

RESET="\x1B[0m"

BLACK="\x1B[30m"
RED="\x1B[31m"
GREEN="\x1B[32m"
YELLOW="\x1B[33m"
BLUE="\x1B[34m"
MAGENTA="\x1B[35m"
CYAN="\x1B[36m"
WHITE="\x1B[37m"

BOLD="\x1B[1m"
UNDERLINE="\x1B[4m"

make

ERASE_ONGOING="\b\b\b\b\b\b\b\b\b\e[0K"

echo -ne "Test with a stack length of 0 : [${YELLOW}ongoing${RESET}]"
if [ "$(./push_swap)" = "" ] && [ "$(./checker)" = "" ]; then
	echo -e "${ERASE_ONGOING}[${GREEN}OK${RESET}]"
else
	echo -e "${ERASE_ONGOING}[${RED}KO${RESET}]"
fi

echo -ne "Test with a stack length of 1 : [${YELLOW}ongoing${RESET}]"
if [ "$(./push_swap $RANDOM)" = "" ] && [ "$(ARG="$RANDOM"; ./push_swap $ARG | ./checker $ARG)" == "OK" ]; then
	echo -e "${ERASE_ONGOING}[${GREEN}OK${RESET}]"
else
	echo -e "${ERASE_ONGOING}[${RED}KO${RESET}]"
fi

echo -ne "Tests with a stack length of 2 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 2)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 3 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 4)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 4 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 4)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 5 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 5)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 6 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 6)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 7 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 7)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 8 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 8)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 9 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 9)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 10 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 10)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 11 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 11)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 12 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 12)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 25 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 25)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 50 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 50)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 100 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 100)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 250 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 5 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 250)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"

echo -ne "Tests with a stack length of 500 : [${YELLOW}ongoing${RESET}]"
RESULT="[${GREEN}OK${RESET}]"
i=0
while [ $i -lt 3 ]; do
	if [ "$(ARG="$(./rand_nb_gen.sh 500)"; ./push_swap $ARG | ./checker $ARG)" != "OK" ]; then
		RESULT="[${RED}KO${RESET}]"
	fi
	i=$[$i+1]
done
echo -e "${ERASE_ONGOING}${RESULT}"
