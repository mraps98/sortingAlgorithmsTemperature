// https://www.tutorialspoint.com/c_standard_library/limits_h.htm

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <limits.h> 
#define Row_N 1024000000



long   toRandoms( )
                             
{ 
    long num =  rand() % (LONG_MAX -1);
   
    return num;
} 


int main() {
  long i;
  char str;
  FILE * fptr;
  fptr = fopen("rand1024.dat", "w");
  if (fptr == NULL) {
    printf("Error in creating output.dat\n");
    return 0;
  }
  
  time_t t;
  srand(time(&t));
  
 
  for (i = 1; i <= Row_N; i++) {
      
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
