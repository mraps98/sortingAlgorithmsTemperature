#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <sys/time.h>
#include "bead.h"
#include "binary_insertion.h"
#include "bogo.h"
#include "bubble.h"
#include "bubble_rec.h"
#include "bucket.h"
#include "comb.h"
#include "cocktail.h"
#include "counting.h"
#include "cycle.h"
#include "gnome.h"
#include "heap.h"
#include "insertion.h"
#include "insertion_rec.h"
#include "merge.h"
#include "mergebu.h"
#include "pancake.h"
#include "partition.h"
#include "pigeonhole.h"
#include "quick.h"
#include "radix.h"
#include "selection.h"
#include "shaker.h"
#include "shell.h"
#include "stooge.h"
#include "tim.h"
#include "tree.h"

int isArraySorted(long[], int);
unsigned long get_num_elements_in_file(char* file_name);
int cmpfunc(const void* a, const void* b);
void print_current_time();
void* acpy(void* dest, const void *src, long len);

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
	double total_copying_time = 0;
	unsigned int number_of_iterations = 1;
	const bool debug_mode = false;


	if(argc < 3){
		printf("Usage: %s <sort_type> <file_name>", argv[0]);
		return -1;
	}
	if(argc == 4){
		number_of_iterations = atoi(argv[3]);
	}
	
	number_of_items = get_num_elements_in_file(argv[2]);
	strcpy(sort_type, argv[1]);
	if(debug_mode){	
		printf("Started program at: ");
		print_current_time();
		printf("Sort type = %s and number of items is %ld and number of iterations is %d\n", sort_type, number_of_items, number_of_iterations);
	}else{
		printf("c, %s, %s, %d, *, ", sort_type, argv[2], number_of_iterations);
		print_current_time();
	}
	
	fp = fopen(argv[2], "r");
	data_original = (long*) calloc(number_of_items, sizeof(long));
	data = (long*) calloc(number_of_items, sizeof(long));
	
	if(debug_mode){	
		printf("Started loading data at ");
		print_current_time();	
	}

	/* Load Data from file */
	while(fgets(line, sizeof(line), fp)){
		data_original[count] = atol(line);
		count++;
	}
	
	fclose(fp);
	
	if(debug_mode){	
		printf("Ended loading data at ");
		print_current_time();	
	}

	/* Sort based on type */
	if(strcmp(sort_type, "bead") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			bead_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "binsertion") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			binsertion_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "bogo") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			bogo_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "bubble") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			bubble_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "bubble_rec") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			bubble_rec_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "bucket") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			bucket_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "comb") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			comb_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "cocktail") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			cocktail_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "counting") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			counting_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "cycle") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			cycle_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "gnome") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			gnome_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "heap") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			heap_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "insertion") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			insertion_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "insertion_rec") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			insertion_rec_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "merge") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			merge_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "mergebu") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			mergebu_sort(data, 0, number_of_items-1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "pancake") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			pancake_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "partition") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			partition_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "pigeonhole") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			pigeonhole_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "quick") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			quick_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if (strcmp(sort_type, "q") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			qsort(data, number_of_items, sizeof(long), cmpfunc);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "radix") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			radix_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "selection") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			selection_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
				printf("Time taken for %dth iteration: %f\n", i+1, ((double) (end - start)) / CLOCKS_PER_SEC);
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "shaker") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			shaker_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "shell") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start = clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			shell_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();	
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "stooge") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start =clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			stooge_sort(data, 0, number_of_items - 1);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "tim") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start =clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			tim_sort(data,number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else if(strcmp(sort_type, "tree") == 0){
		int i;
		for(i = 0; i < number_of_iterations; i++){
			start =clock();
			acpy(data, data_original,  number_of_items);
			end = clock();
			total_copying_time += ((double) (end - start)) / CLOCKS_PER_SEC;;
			if(debug_mode){
				printf("Time taken to copy data_original to data: %06f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
				printf("Started iteration %d of sorting data at ", i+1);
				print_current_time();
			}
			start = clock();
			tree_sort(data, number_of_items);
			end = clock();
			if(debug_mode){
				printf("Stopped iteration %d of sorting data at ", i+1);
				print_current_time();
			}else{
				printf("c, %s, %s, %d, %d/%d, %f\n", sort_type, argv[2], number_of_iterations, i+1, number_of_iterations, ((double) (end - start)) / CLOCKS_PER_SEC);
			}
			total_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
		average_cpu_time_used = total_cpu_time_used / number_of_iterations;
	}else{
		printf("incorrect sort_type entered\n");
		return -1;
	}	
		
	
	if(debug_mode){
		printf("Total time taken for %d iterations is %f seconds\n", number_of_iterations, total_cpu_time_used);
		printf("Average time taken for %d iterations is %f seconds\n", number_of_iterations, average_cpu_time_used);
		if(isArraySorted(data, number_of_items)){
			printf("Validation: Array has been sorted\n");
		}else{
			printf("Validation: Array not sorted\n");
		}
		printf("Ended program at: ");
		print_current_time();	
	}else{
		printf("c, %s, %s, %d, #, %06f, %06f, ", sort_type, argv[2], number_of_iterations, average_cpu_time_used, total_copying_time);
		print_current_time();
	}

	
	free(data);
	free(data_original);

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

int cmpfunc(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

void print_current_time(){
	struct tm* tm_struct;
	struct timeval tval_now;
	time_t t;
	t = time(NULL);
	tm_struct = localtime(&t);	
	gettimeofday(&tval_now, NULL); 	
	printf("%02d:%02d:%02d", tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);
	printf(":%06ld\n", tval_now.tv_usec);
}

void* acpy(void* dest, const void *src, long len){
	long *d = dest;
	const long *s = src;
	while(len--){
		*d++ = *s++;
	}
	return dest;
}
