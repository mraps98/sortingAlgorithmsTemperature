#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
	
	/* declare variables */
	unsigned int number_of_items = 1000;
	char file_name[50];
	FILE* fp;
	char line[256];
	size_t len = 0;
	ssize_t read;
	long* data;
	unsigned int count = 0;
	char sort_type[20];
	char number_of_items_string[10];
	
	if(argc > 1){	
		strncpy(sort_type, argv[1], 50);
		strncpy(number_of_items_string, argv[2], 10);
		printf("Sort type = %s and number of items is %s", sort_type, number_of_items_string);
		if(number_of_items_string == "1k"){
			number_of_items = 1000;
		}else if(number_of_items_string == "2k"){
			number_of_items = 2000;
		}else if(number_of_items_string == "3k"){
			number_of_items = 3000;
		}else if(number_of_items_string == "4k"){
			number_of_items = 4000;
		}else if(number_of_items_string == "5k"){
			number_of_items = 5000;
		}else if(number_of_items_string == "6k"){
			number_of_items = 6000;
		}else if(number_of_items_string == "7k"){
			number_of_items = 7000;
		}else if(number_of_items_string == "8k"){
			number_of_items = 8000;
		}else if(number_of_items_string == "9k"){
			number_of_items = 9000;
		}else{
			number_of_items = 1000;
		}
	}else{
		printf("Sort type = bubble and number of items is 1k");
	}
	/* generate file name */
	sprintf(file_name, "../../generatingData/data/long/long%d.txt", number_of_items);
	
	fp = fopen(file_name, "r");
	data = calloc(number_of_items, sizeof(long));
	
	while(fgets(line, sizeof(line), fp)){
		data[count] = atoi(line);
		count++;
	}
	
	printf("before:\n");
	for(int i = 0; i < number_of_items; i++){
		printf("%ld, ", data[i]);
	}
	
	bubble_sort(data, 0, number_of_items);
	printf("after:\n");
	for(int i = 0; i < number_of_items; i++){
		printf("%ld, ", data[i]);
	}
	
	fclose(fp);
	free(data);
	
	return 0;
}
