#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quick_t.h"

long get_num_duplicates(duplicates_t* a, int n);

int main(int argc, char* argv[]){
	
	/*  Define struct */
	typedef struct duplicates{
		long location;
		long element;
	}duplicates_t;

	/* declare variables */
	duplicates_t* data;
	unsigned long num_elements = 0;
	FILE* fp;
	char line[256];
	unsigned int count = 0;
	char file_name_sorted[256];
	int i;


	/* If file name not specified */
	if(argc < 2){
		printf("Usage: %s <file_name>\n", argv[0]);
		return 0;
	}
	
	/* Count how many elements in file */
	fp = fopen(argv[1], "r");
	if(fp){
		while(fgets(line, sizeof(line), fp)){
			num_elements++;
		}
	}else{
		printf("File not found\n");
		return 1;
	}

	/* Allocate struct from data [location, element] */
	data = (duplicates_t*) malloc(num_elements * sizeof(duplicates_t));

	/* Load data into array of structs */
	printf("Reading data from file %s with %ld elements\n", argv[1], num_elements);
	fp = fopen(argv[1], "r");
	while(fgets(line, sizeof(line), fp)){
		data[count].element = atoi(line);
		data[count].location = count;
		count++;
	}
	fclose(fp);

	/* Enter how many duplicates */
	long num_duplicates = get_num_duplicates(data, num_elements);
	printf("The data has %ld duplicates\n", num_duplicates);
	printf("The data has %f%% duplicates\n", ((float) num_duplicates / num_elements * 100));

	/*Add last 1000 of sorted array to file */
	sprintf(file_name_sorted, "%ldsorted.dat", num_elements);
	printf("Outputing last 100 elements of the sorted array to ./%s\n", file_name_sorted);
	fp = fopen(file_name_sorted, "w");
	for(i = 0; i < num_elements; i++){
		fprintf(fp, "%ld\n", data[i]);
	}

	/* Free memory */
	fclose(fp);
	free(data);
	return 0;
}

long get_num_duplicates(duplicates_t* a, int n){
	FILE* fp;
	fp = fopen("duplicates.log", "w");
    long i;
    unsigned long num_duplicates = 0;
    quick_sort(a, 0, n -1);
    for(i = 0; i < n; i++){
		if(a[i].element == a[i+1].element){ // use strcmp not ==
			num_duplicates++;
			// fprintf(fp, "Duplicate: %ld at index %ld\n", a[i], i);
		}
    }
	fclose(fp);
    return num_duplicates;
}