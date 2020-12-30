// https://www.tutorialspoint.com/c_standard_library/limits_h.htm

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <limits.h> 
#define Row_N 2000000


long   toSmallRandoms( )
                             
{ 
    long num =  rand() % (LONG_MAX /100);
   
    return num;
} 


long   toRandoms( )
                             
{ 
    long num =  rand() % (LONG_MAX -1);
   
    return num;
} 


int main(int argc, char* argv[]) {
  
  if(argc < 2){
    printf("Usage: ./%s <num_elements_to_generate>\n", argv[0]);
    return 0;
  }
  char file_name[256];
  long i;
  char str;
  FILE * fptr;


  sprintf(file_name, "rand%ld.dat", atol(argv[1]));
  fptr = fopen(file_name, "w");
  if (fptr == NULL) {
    printf("Error in creating output.dat\n");
    return 0;
  }
  
  time_t t;
  srand(time(&t));
  
 
  for (i = 1; i <= atol(argv[1]); i++) {
      
      //printf("%ld\n", toRandoms());
    fprintf(fptr, "%ld\n", toRandoms());
  }
  fclose(fptr);
  // fptr = fopen ("rand2.dat", "r");  
  // str = fgetc(fptr);
	// while (str != EOF)
	// 	{
	// 		printf ("%c", str);
	// 		str = fgetc(fptr);
	// 	}
  // fclose(fptr);
  return 0;
}
