#!/bin/bash

EXPECTED_ARGS=1

if [ $# -lt $EXPECTED_ARGS ]; then
	echo "Error: Too few arguments." >&2
	echo "Usage: $0 <number-of-elements>" >&2
	exit 1
elif [ $# -gt $EXPECTED_ARGS ]; then
	echo "Error: Too many arguments." >&2
	echo "Usage: $0 <number-of-elements>" >&2
	exit 1
fi

OUTPUT_FILE="out"
TARGET_STRING="CORRECT"
ELEMENTS=$1
ITER=5000

max_comp=0

> "$OUTPUT_FILE"

for ((i = 1; i <= $ITER; i++)); do
	./PmergeMe `shuf -i 1-10000 -n $ELEMENTS | tr "\n" " "` >> "$OUTPUT_FILE"

	comparisons=$(tail -n2 "$OUTPUT_FILE" | head -n1)
	last_line=$(tail -n1 "$OUTPUT_FILE")

	if ((comparisons > max_comp)); then
		max_comp=$comparisons
	fi

	if [[ "$last_line" != "$TARGET_STRING" ]]; then
		echo "Array wasn't sorted or it had duplicate values."
		exit
	fi

done

echo "Performed $ITER tests with random elements. Element range was 1-10000."
echo "Maximum comparisons for $ELEMENTS elements was: $max_comp"

rm $OUTPUT_FILE
