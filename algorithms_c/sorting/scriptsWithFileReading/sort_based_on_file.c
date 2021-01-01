#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "bogo.h"
#include "bubble.h"
#include "bucket.h"
#include "comb.h"
#include "counting.h"
#include "cycle.h"
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "pancake.h"
#include "quick.h"
#include "radix.h"
#include "selection.h"
#include "shaker.h"
#include "shell.h"

int isArraySorted(long[], int);
unsigned long get_num_elements_in_file(char* file_name);

int main(int argc, char* argv[]){
	
	/* declare variables */
	unsigned long number_of_items;
	FILE* fp;
	char line[256];
	size_t len = 0;
	ssize_t read;
	long* data_original;
	long* data;
	unsigned int count = 0;
	char sort_type[20];
	clock_t start, end;
	double average_cpu_time_used = 0;
	double total_cpu_time_used = 0;
	unsigned int number_of_iterations = 1;
	

	if(argc < 3){
		printf("Usage: %s <sort_type> <file_name>", argv[0]);
		return -1;
	}
	if(argc == 4){
		number_of_iterations = atoi(argv[4]);
	}
	number_of_items = get_num_elements_in_file(argv[2]);
	strcpy(sort_type, argv[1]);
	printf("Sort type = %s and number of items is %ld and number of iterations is %d\n", sort_type, number_of_items, number_of_iterations);
	
	
	fp = fopen(argv[2], "r");
	data_original = (long*) calloc(number_of_items, sizeof(long));
	data = (long*) calloc(number_of_items, sizeof(long));
	
	/* Load Data from file */
	while(fgets(line, sizeof(line), fp)){
		data_original[count] = atoi(line);
		count++;
	}
	
	fclose(fp);

	// printf("before:\n");
	// for(int i = 0; i < number_of_items; i++){
		// printf("%ld, ", data[i]);
	// }
	
	/* Sort based on type */
	if(strcmp(sort_type, "bubble") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			bubble_sort(data, 0, number_of_items - 1);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "bogo") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			bogo_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "bucket") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			bucket_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "comb") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			comb_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "counting") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			counting_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "cycle") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			cycle_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "heap") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			heap_sort(data, 0, number_of_items - 1);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "insertion") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			insertion_sort(data, 0, number_of_items - 1);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "merge") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			merge_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "pancake") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			pancake_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "quick") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			quick_sort(data, 0, number_of_items - 1);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "radix") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			radix_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "selection") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			selection_sort(data, 0, number_of_items - 1);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "shaker") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			shaker_sort(data, number_of_items);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "shell") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			memcpy(data, data_original, number_of_items);
			start = clock();
			shell_sort(data, 0, number_of_items - 1);
			end = clock();
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else{
		printf("incorrect sort_type entered\n");
	}	
	// printf("after:\n");
	// for(int i = 0; i < number_of_items; i++){
	// 	printf("%ld, ", data[i]);
	// }
	
	printf("Total time taken for %d iterations is %f seconds\n", number_of_iterations, total_cpu_time_used);
	printf("Average time taken for %d iterations is %f seconds\n", number_of_iterations, average_cpu_time_used);
	if(isArraySorted(data, number_of_items)){
		printf("Validation: Array has been sorted\n");
	}else{
		printf("Validation: Array not sorted\n");
	}
	free(data);
	
	return 0;
}

int isArraySorted(long s[], int n) {
  int a = 1, d = 1, i = 0;

  while ((a == 1 || d == 1) && i < n - 1) {
    if (s[i] < s[i+1])
      d = 0;
    else if (s[i] > s[i+1])
      a = 0;
    i++;
  }

  if (a == 1)
    return 1;
  else if (d == 1)
    return 2;
  else
    return 0;
}

unsigned long get_num_elements_in_file(char* file_name){
	unsigned long num_elements = 0;
	char line[256];
	FILE* fp = fopen(file_name, "r");
	if(fp){
		while(fgets(line, sizeof(line), fp)){
			num_elements++;
		}
	}else{
		printf("File not found\n");
		return 1;
	}
	fclose(fp);
	return num_elements;
}
