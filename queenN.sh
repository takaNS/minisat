#!/bin/sh
if test $# -eq 0; then
	/bin/echo -n "How Many Queens?:"
	read QUEENS
else
	QUEENS=$1
fi

echo $QUEENS | grep -E "1|2|3|4|5|6|7|8|9|0" 1> /dev/null

if test $? -ne 0; then
	echo "Please Type Numbar." 1>&2
	exit 1
elif test $QUEENS -lt 4; then
	echo "Please Type Larger Than 3." 1>&2
	exit 1
# elif test $QUEENS -ge 100; then
# 	echo "Please Type smaler Than 100." 1>&2
# 	exit 1
fi

MINISAT=`which minisat`

if test $? -ne 0; then
	test $MINISAT
	if test $? -ne 0; then
		echo "Where Is Minisat?" 1>&2
		echo "Please Run: MINISAT=/path/to/minisat" 1>&2
		echo "More Info: README.txt" 1>&2
		exit 1
	fi
fi


# echo "start gcc."
# gcc -std=c99 ./cleate_cnf.c -o ./cleate_cnf.out
# echo "complete gcc."
# echo "cleate cnf."
./cleate_cnf.out $QUEENS > ./queenN.cnf
echo "complete cnf."
$MINISAT ./queenN.cnf ./solved.txt 2> ./SAT_error.log 1> ./SAT.log
echo "create date for mapping."
cat /dev/null > ./queenN.txt
for (( i = 0; i < $QUEENS; i++ )); do
	for (( j = 0; j < $QUEENS; j++ )); do
		sed -n 2p ./solved.txt | cut -d" " -f`expr $i \* $QUEENS + $j + 1` >> ./queenN.txt
	done
done
echo "complete data."
echo "careate map."
# gcc -std=c99 ./mapping.c -o mapping.out
./mapping.out $QUEENS > ./mapping.txt
cat ./mapping.txt
echo "complete map."
