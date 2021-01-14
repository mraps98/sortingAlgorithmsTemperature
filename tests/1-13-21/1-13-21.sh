#!/bin/sh

FILE_NAME="/home/preet/projects/sortingAlgorithmsTemperature/generating_data/rand300k.dat"
NUMBER_OF_ITERATIONS=10
PROG_C=/home/preet/projects/sortingAlgorithmsTemperature/algorithms_c/sort/sort_based_on_file.out
PROG_J="java -cp /home/preet/projects/sortingAlgorithmsTemperature/algorithms_java/sort/ SortBasedOnFile"
PROG_P="python3 /home/preet/projects/sortingAlgorithmsTemperature/algorithms_python/sort/main.py"

for SORT_TYPE in binsertion bubble cocktail comb cycle gnome heap insertion merge mergebu pancake quick radix selection shell tim
do
	$PROG_C $SORT_TYPE $FILE_NAME $NUMBER_OF_ITERATIONS
#	$PROG_J $SORT_TYPE $FILE_NAME $NUMBER_OF_ITERATIONS
#	$PROG_P $SORT_TYPE $FILE_NAME $NUMBER_OF_ITERATIONS
done
