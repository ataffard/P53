#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Description: Congruent Random Number Generator

  Author: Anyes Taffard
*/

//Declare the variables as global so that the previous iteration 
//values are available at each new call
int seed = 0;
int next = 1;
int A = 16807;
int C = 0;   
int M = 2147483647;
int q = 127773; // M / A
int r = 2836;   // M % A

const unsigned int RANDMAX=2147483646;   // = M-1

const int debug =0; //debug mode 1
//__________________________________________
// Linear congruent RNG
// This version is prone to integer wrap around
unsigned int random1(){
  if(seed){
    next = seed;
    seed=0;
  }
  next = next * A + C;
  if(debug) printf("\t A %i M %i next %i res %i \n", A, M, next, (next%M) );
  return (unsigned int) next % M;   //UI to protect against <0 due to wrap around
}
//__________________________________________
// Linear congruent RNG
// With protection for overflow (Park-Miller's)
int random2(){
  if(seed){
    next = seed;
    seed=0;
  }
  next = A * (next % q) - r * (next / q);
  if(next<0) next += M;
  if(debug) printf("\t A %i M %i next %i res %i \n", A, M, next, (next%M) );
  return next;
}

//__________________________________________________
//__________________________________________________
int main() {
  int N = 100000;

  seed=10;
  srand( time(NULL) * seed); //Randomize seed of C RNG

  for(int i=0; i<N; i++){
    //Congruent RNG
    double randX = (double) random1();
    double randY = (double) random1();
    double x = randX / ((double) RANDMAX);
    double y = randY / ((double) RANDMAX);

    //Congruent RNG Park-Miller
    /*
    double randX = (double) random2();
    double randY = (double) random2();
    double x = randX / ((double) RANDMAX);
    double y = randY / ((double) RANDMAX);
    */

    //Stdlib RNG (congruent type)
    /*
    double randX = (double) rand();
    double randY = (double) rand();
    double x = randX / ((double) RAND_MAX+1);
    double y = randY / ((double) RAND_MAX+1);
    */

    printf("%f %f\n",x,y);
  }
  
  return 0;
}
