#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include "quickt.h"

long get_num_duplicates(duplicates_t* a, int n);
void output_data_to_file(duplicates_t* data, unsigned long num_elements, char file_name[256]);

int main(int argc, char* argv[]){
	
	/*  Define struct */
	typedef struct duplicates{
		long location;
		long element;
		unsigned int flag;
	}duplicates_t;

	/* declare variables */
	duplicates_t* data;
	unsigned long num_elements = 0;
	FILE* fp;
	char line[256], line2[256];
	unsigned int count = 0;
	char file_name_sorted[256];
	int i;
	unsigned int duplicates_exist = 0;
	unsigned long num_duplicates;
	FILE* fp2;
	const char delim[] = ", ";
	char* token;
	unsigned long temp_el, temp_loc, new_rand;
	time_t t;


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
	data = (duplicates_t*) calloc(num_elements, sizeof(duplicates_t));

	/* Load data into array of structs */
	printf("Reading data from file %s with %ld elements\n", argv[1], num_elements);
	fp = fopen(argv[1], "r");
	while(fgets(line, sizeof(line), fp)){
		data[count].element = (long) atol(line);
		data[count].location = (long) count;
		// printf("Read %d at %d\n", atol(line), count);
		// printf("Read %ld at %ld\n", data[count].element, data[count].location);
		count++;
	}
	fclose(fp);

	/* Enter how many duplicates */
	num_duplicates = get_num_duplicates(data, num_elements);
	printf("The data has %ld duplicates\n", num_duplicates);
	printf("The data has %f%% duplicates\n", ((float) num_duplicates / num_elements * 100));

	/*Add last 1000 of sorted array to file */
	sprintf(file_name_sorted, "%ldsorted.dat", num_elements);
	output_data_to_file(data, num_elements, file_name_sorted);

	/* Free memory */
	free(data);

	/* Remove duplicates */
	fp = fopen(file_name_sorted, "r");
	while(fgets(line, sizeof(line), fp)){
		token = strtok(line, delim);
		temp_el = atol(token);
		token = strtok(NULL, delim);
		temp_loc = atol(token);
		token = strtok(NULL, delim);
		if(strcmp(token, "1\n") == 0){
			printf("%ld, %ld, %c\n", temp_el, temp_loc, token[0]);

			/* Replace the duplicate with a new random */
			fp2 = fopen(argv[1], "w");
			srand(time(&t));
			new_rand = rand() % (LONG_MAX - 1);
			count = 0;
			while(fgets(line2, sizeof(line2), fp2)){
				if(count == atoi(&token[0])){
					// printf("Line: %s\n", line);
					// fprintf(fp, "%ld", new_rand);
				}else{
					
				}
				count++;
			}
			fclose(fp2);
		}
	}
	fclose(fp);

	return 0;
}

long get_num_duplicates(duplicates_t* a, int n){
    long i;
    unsigned long num_duplicates = 0;
    quick_sort(a, 0, n -1);
    for(i = 0; i < n; i++){
		if(a[i].element == a[i+1].element){
			num_duplicates++;
			a[i+1].flag = 1;
		}
    }
    return num_duplicates;
}

void output_data_to_file(duplicates_t* data, unsigned long num_elements, char file_name[256]){
	FILE* fp;
	int i;
	printf("Outputing all elements of the sorted array to ./%s\n", file_name);
	fp = fopen(file_name, "w");
	for(i = 0; i < num_elements; i++){
		fprintf(fp, "%ld, %ld, %d\n", data[i].element, data[i].location, data[i].flag);
	}
	fclose(fp);
}