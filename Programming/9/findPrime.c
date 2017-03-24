#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  Description: Given an array (1000 max) of int, 
               return a array of the prime numbers

  Prime number is a number > 1 that has no positive divisor 
  other than 1 and itself

  Author: Anyes Taffard
*/

const int debug  = 0;     //1: debug mode
const int NLINES = 1000;

//Read file up to 1000 lines of numbers into an array
void readFile(char fileName[], 
	      int* nEntries, 
	      long unsigned int array[]); 

//Given input array, return array of all the primes
void findPrimes(int nIn, int* nOut, 
		long unsigned int input[], 
		long unsigned int output[]);

//return 1 is the number is a prime
int isPrime(long unsigned int n);

//sort array in increasing number
void sort1DArray(int n, long unsigned int array[]);

//print array content
void print1DArray(int n, long unsigned int array[]);

//___________________________________________
//___________________________________________
int main(){
  //Read file into array
  long unsigned int aNums[NLINES];
  int iLines=0;
  readFile("findPrime.dat",&iLines,aNums);

  //Find all the primes and store them into array
  long unsigned int aPrimes[NLINES];
  int nPrimesFound=0;
  findPrimes(iLines, &nPrimesFound, aNums, aPrimes);

  //sort the array
  sort1DArray(nPrimesFound, aPrimes);

  //print the outcome
  print1DArray(nPrimesFound, aPrimes);
  
  return 0;
}

//___________________________________________
void readFile(char fileName[], 
	      int* nEntries, 
	      long unsigned int array[])
{
  FILE* fPtr;
  fPtr = fopen(fileName,"r"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  
  *nEntries=0;
  while( !feof(fPtr) && *nEntries<NLINES ){
    fscanf(fPtr,"%lu ",&array[(*nEntries)++]);
  }
  (*nEntries)--; //-1 to remove the line w/ EOF
  if(debug) printf("Read in %i numbers \n",*nEntries);
  fclose(fPtr);
}
//___________________________________________
void findPrimes(int nIn, int *nOut, 
		long unsigned int input[], 
		long unsigned int output[])
{
  *nOut=0;
  for(int i=0; i<nIn; i++){
    if(debug) printf("testing %lu \n",input[i]);
    if( isPrime(input[i]) ){
      output[(*nOut)++] = input[i];
    }
  }
}
//___________________________________________
int isPrime(long unsigned int n)
{
  // Find if the number is not a prime using trial division 
  // http://en.wikipedia.org/wiki/Prime_number
  // http://en.wikipedia.org/wiki/Primality_test
  if( n==1 || (n!=2 && n%2==0) ){
    return 0; 
  }
  else{
    long unsigned int sqrt_n = (long unsigned int) sqrt(n);
    for(long unsigned int i=3; i<= sqrt_n; i+=2 ){
      if( n%i==0 ) return 0;
    }
    if(debug) printf("\tIs prime\n");
    return 1;
  }
}
//___________________________________________
void sort1DArray(int n, long unsigned int array[])
{
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(array[i]>array[j]){
	long unsigned int temp = array[j];
	array[j]=array[i];
	array[i]=temp;
      }
    }
  }
}
//___________________________________________
void print1DArray(int n, long unsigned int array[])
{
  if(n==0) printf("No prime number found. \n");
  else     printf("Found %i prime numbers: \n",n);
  for(int i=0; i<n; i++){
    printf("%lu ",array[i]);
    //return carriage after 5 numbers
    if( i>0 && i%5==0 ) printf("\n"); 
  }
  printf("\n");
}
