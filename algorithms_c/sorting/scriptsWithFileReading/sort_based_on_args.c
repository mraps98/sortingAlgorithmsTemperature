#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "bubble.h"
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "selection.h"
#include "shaker.h"
#include "shell.h"

int isArraySorted(long[], int);

int main(int argc, char* argv[]){
	
	/* declare variables */
	unsigned int number_of_items = 1000;
	char file_name[50];
	FILE* fp;
	char line[256];
	size_t len = 0;
	ssize_t read;
	long* data_original;
	long* data;
	unsigned int count = 0;
	char sort_type[20] = "bubble";
	char number_of_items_string[10] = "1k";
	clock_t start, end;
	double average_cpu_time_used = 0;
	double total_cpu_time_used = 0;
	unsigned int number_of_iterations = 1;
	
	if(argc > 1){	
		if(argc > 2){
			strncpy(number_of_items_string, argv[2], 10);
		}
		strncpy(sort_type, argv[1], 50);
		if(strcmp(number_of_items_string, "1k") == 0){
			number_of_items = 1000;
		}else if(strcmp(number_of_items_string, "2k") == 0){
			number_of_items = 2000;
		}else if(strcmp(number_of_items_string, "3k") == 0){
			number_of_items = 3000;
		}else if(strcmp(number_of_items_string, "4k") == 0){
			number_of_items = 4000;
		}else if(strcmp(number_of_items_string, "5k") == 0){
			number_of_items = 5000;
		}else if(strcmp(number_of_items_string, "6k") == 0){
			number_of_items = 6000;
		}else if(strcmp(number_of_items_string, "7k") == 0){
			number_of_items = 7000;
		}else if(strcmp(number_of_items_string, "8k") == 0){
			number_of_items = 8000;
		}else if(strcmp(number_of_items_string, "9k") == 0){
			number_of_items = 9000;
		}else{
			number_of_items = 1000;
		}
		if(argc > 3){
			number_of_iterations = atoi(argv[3]);
		}
	}
	printf("Sort type = %s and number of items is %s and number of iterations is %d\n", sort_type, number_of_items_string, number_of_iterations);
	
	/* generate file name */
	sprintf(file_name, "../../../generatingData/data/long/long%d.txt", number_of_items);
	
	fp = fopen(file_name, "r");
	data_original = calloc(number_of_items, sizeof(long));
	data = calloc(number_of_items, sizeof(long));
	
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
