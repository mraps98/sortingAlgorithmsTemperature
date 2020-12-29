#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NUMBER LONG_MAX

int main(){
	time_t t;
	srand((unsigned) time(&t));
	
	unsigned int NUMBER_OF_ELEMENTS;
	FILE* fp;
	
	for(int i = 0; i <= 8; i++){
		NUMBER_OF_ELEMENTS = (i+1)*1000;
		long* data = calloc(NUMBER_OF_ELEMENTS, sizeof(long));
		char file_name[50];
		
		sprintf(file_name, "./data/long/long%d.txt", NUMBER_OF_ELEMENTS);
		fp = fopen(file_name, "w");

		for(int i = 0; i < NUMBER_OF_ELEMENTS; i++){
			data[i] = rand() % MAX_NUMBER;
		}
		
		for(int i = 0; i < NUMBER_OF_ELEMENTS; i++){
			if(i == NUMBER_OF_ELEMENTS-1){
				fprintf(fp, "%ld", data[i]);
			}else{
				fprintf(fp, "%ld\n", data[i]);
			}
		}
		
		free(data);
		fclose(fp);		
	}
	return 0;
}
