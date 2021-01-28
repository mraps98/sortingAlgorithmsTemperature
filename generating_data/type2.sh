#!/bin/bash

#THIS SCRIPT WILL MAKE TYPE 2 DATA

#CLEAN AND MAKE
make clean
make

#VARIABLES
declare -i TOTAL_SIZE
TOTAL_SIZE=$1
SORTING_ALGORITHMS_PATH="/home/preet/projects/c/sortingAlgorithmsTemperature/"
GENERATE_RANDOM_PATH="${SORTING_ALGORITHMS_PATH}/generating_data/generate_random_numbers_file.out"
REMOVE_DUPLICATES_PATH="${SORTING_ALGORITHMS_PATH}/checkDuplicates/removeDuplicates.out"
SORT_PATH="${SORTING_ALGORITHMS_PATH}/algorithms_c/sort/sort_based_on_file.out"

#MAKE ASCENDING
$GENERATE_RANDOM_PATH $TOTAL_SIZE
$REMOVE_DUPLICATES_PATH "./rand${TOTAL_SIZE}.dat"
$REMOVE_DUPLICATES_PATH "./rand${TOTAL_SIZE}.dat"
$REMOVE_DUPLICATES_PATH "./rand${TOTAL_SIZE}.dat"
$REMOVE_DUPLICATES_PATH "./rand${TOTAL_SIZE}.dat"
$SORT_PATH quick "./rand${TOTAL_SIZE}.dat" 1 1
mv "./sorted_output.dat" temp.dat
tac temp.dat >> "./type2_${TOTAL_SIZE}.dat"
