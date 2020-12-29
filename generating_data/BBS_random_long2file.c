/*
Long Range
// https://www.tutorialspoint.com/c_standard_library/limits_h.htm

Minimal primes
https://en.wikipedia.org/wiki/List_of_prime_numbers

BBS algortihm
https://en.wikipedia.org/wiki/Blum_Blum_Shub
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <limits.h> 
#define Row_N 2000000

long seed =3; //Mersenne primes

long getRandoms(){
    
    long p,q;
    long n, k;
    p=9649;  //Minimal primes
    q=60649; //Minimal primes
    
    n= p*q;
    k= (seed * seed )% n;
    
    seed =k;
    
    return k;
    
}

long   toRandoms( )
                             
{ 
    
    
    long num =  rand() % (LONG_MAX -1);
   
    return num;
} 


int main() {
  long i;
  char str;
  FILE * fptr;
  fptr = fopen("rand2.dat", "w");
  if (fptr == NULL) {
    printf("Error in creating output.dat\n");
    return 0;
  }
  
  time_t t;
  srand(time(&t));
  
 
  for (i = 1; i <= Row_N; i++) {
      
    //printf("*%ld, %ld\n", getRandoms(), seed);
    fprintf(fptr, "%ld\n", getRandoms());
    
  }
  fclose(fptr);
  // fptr = fopen ("rand512.dat", "r");  
  // str = fgetc(fptr);
	// while (str != EOF)
	// 	{
	// 		printf ("%c", str);
	// 		str = fgetc(fptr);
	// 	}
  // fclose(fptr);
  return 0;
}
