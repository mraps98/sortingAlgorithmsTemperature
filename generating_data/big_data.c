#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(){
	time_t t;
	srand((unsigned) time(&t));

	unsigned int NUMBER_OF_ELEMENTS;
	long* data;
	FILE* fp;
	char file_name[50];

	long i;	
	for(i = 125000000; i <= 128 * 125000000; i++){
		data = (long*) calloc(i, sizeof(long));
		
		sprintf(file_name, "./bigdata/%ld.txt", i);
		fp = fopen(file_name, "w");

		int j;
		for(j = 0; j < i; j++){
			data[i] = rand() % LONG_MAX;
			if(j == i - 1){
				fprintf(fp, "%ld", data[i]);
			}else{
				fprintf(fp, "%ld\n", data[i]);
			}
		}
		
		free(data);
		fclose(fp);
	}
	printf("Done\n");
	return 0;
}