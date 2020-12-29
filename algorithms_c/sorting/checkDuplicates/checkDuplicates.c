#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quick.h"

int isArraySorted(long[], int);
long get_num_duplicates(long* a, int n);

int main(int argc, char* argv[]){
	
	/* declare variables */
	long* data;
	unsigned long num_elements = 0;
	FILE* fp;
	char line[256];
	unsigned int count = 0;
	char file_name_sorted[256];
	int i;

	if(argc < 2){
		printf("Usage: %s <file_name>\n", argv[0]);
		return 0;
	}
	
	/* Count how many elements in file */

	fp = fopen(argv[1], "r");
	while(fgets(line, sizeof(line), fp)){
		num_elements++;
	}

	// num_elements = atoi(argv[2]);
	data = (long*) calloc(num_elements, sizeof(long));

	printf("Reading data from file %s with %ld elements\n", argv[1], num_elements);

	/* Load data into array */
	fp = fopen(argv[1], "r");
	while(fgets(line, sizeof(line), fp)){
		data[count] = atoi(line);
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
	fclose(fp);


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

long get_num_duplicates(long* a, int n){
	FILE* fp;
	fp = fopen("duplicates.log", "w");
    long i;
    unsigned long num_duplicates = 0;
    quick_sort(a, 0, n -1);
    for(i = 0; i < n; i++){
		if(a[i] == a[i+1]){ // use strcmp not ==
			num_duplicates++;
			// get the index as well | offer details
			// count howmany, whats the element, which row_number.  >> "log file"
			fprintf(fp, "Duplicate: %ld at index %ld\n", a[i], i);
		}
    }
	fclose(fp);
    return num_duplicates;
}
