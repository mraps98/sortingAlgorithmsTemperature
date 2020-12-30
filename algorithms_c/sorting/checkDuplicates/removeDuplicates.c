#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include "quick.h"
#include "quickt.h"

long get_num_duplicates(duplicates_t* a, int n);
void output_data_to_file(duplicates_t* data, unsigned long num_elements, char file_name[256]);
unsigned long get_num_elements_in_file(char* file_name);
void load_data_into_struct_array(duplicates_t* data, char* file_name);

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
	int i, j;
	unsigned int duplicates_exist = 0;
	unsigned long num_duplicates;
	FILE* fp2;
	const char delim[] = ", ";
	char* token;
	unsigned long temp_el, temp_loc, new_rand;
	time_t t;
	unsigned long* duplicate_indices;

	/* If file name not specified */
	if(argc < 2){
		printf("Usage: %s <file_name>\n", argv[0]);
		return 0;
	}
	
	/* Count how many elements in file */
	num_elements = get_num_elements_in_file(argv[1]);

	/* Allocate struct from data [location, element] */
	data = (duplicates_t*) calloc(num_elements, sizeof(duplicates_t));

	/* Load data into array of structs */
	printf("Reading data from file %s with %ld elements\n", argv[1], num_elements);
	load_data_into_struct_array(data, argv[1]);

	/* Enter how many duplicates */
	num_duplicates = get_num_duplicates(data, num_elements);
	printf("The data has %ld duplicates\n", num_duplicates);

	if (num_duplicates > 0 ){

		printf("The data has %f%% duplicates\n", ((float) num_duplicates / num_elements * 100));

		/*Add element, location, flag of sorted array to file */
		sprintf(file_name_sorted, "%ldsorted.dat", num_elements);
		output_data_to_file(data, num_elements, file_name_sorted);

		/* Free memory */
		free(data);

		/* Find duplicated indices */
		fp = fopen(file_name_sorted, "r");
		// fp2 = fopen("duplicates.log", "w");
		duplicate_indices = (unsigned long*) calloc(num_duplicates, sizeof(unsigned long));
		count = 0;
		while(fgets(line, sizeof(line), fp)){
			token = strtok(line, delim);
			temp_el = atol(token);
			token = strtok(NULL, delim);
			temp_loc = atol(token);
			token = strtok(NULL, delim);
			if(strcmp(token, "1\n") == 0){
				// printf("%ld, %ld, %c\n", temp_el, temp_loc, token[0]);
				// fprintf(fp2, "%ld, %ld, %c\n", temp_el, temp_loc, token[0]);
				duplicate_indices[count] = temp_loc;
				count++;
			}
		}
		fclose(fp2);
		fclose(fp);


		/*  Sort duplicate indices*/
		quick_sort(duplicate_indices, 0, num_duplicates - 1);

		/* Replace duplicates */
		srand(time(&t));
		fp = fopen(argv[1], "r");
		fp2 = fopen("temp.dat", "w");
		count = 0; /* Line Count */
		i = 0; /* Duplicate index */
		while(fgets(line, sizeof(line), fp)){
			if(count == (unsigned int) duplicate_indices[i]){
				printf("Replacing %dth duplicate\n", i + 1);
				// printf("found element %s at line %d, now replacing\n", line, count);
				new_rand = rand() % (LONG_MAX - 1);
				fprintf(fp2, "%ld\n", new_rand);
				i++;
			}else{
				// printf("copying normally\n");
				fprintf(fp2, "%s", line);
			}
			count++;
		}
		fclose(fp);
		fclose(fp2);

		/* Replace original with temp*/
		fp = fopen("temp.dat", "r");
		fp2 = fopen(argv[1], "w");
		count = 0;
		while(fgets(line, sizeof(line), fp)){
			fprintf(fp2, "%s", line);
			// printf("Row %d", count);
			count++;
		}
		fclose(fp);
		fclose(fp2);
		
		free(duplicate_indices);

		remove("temp.dat");
	}
	return 0;
}

long get_num_duplicates(duplicates_t* a, int n){
    long i;
    unsigned long num_duplicates = 0;
    quick_sortt(a, 0, n -1);
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

void load_data_into_struct_array(duplicates_t* data, char* file_name){
	FILE* fp = fopen(file_name, "r");
	unsigned int count = 0;
	char line[256];
	while(fgets(line, sizeof(line), fp)){
		data[count].element = (long) atol(line);
		data[count].location = (long) count;
		// printf("Read %d at %d\n", atol(line), count);
		// printf("Read %ld at %ld\n", data[count].element, data[count].location);
		count++;
	}
	fclose(fp);
}
