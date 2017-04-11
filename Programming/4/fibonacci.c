#include <stdio.h>
#include <time.h>
/*
  Description: Calculate a Fibonacci sequence
  Fn = F(n-1) + F(n+1)
  Seeds F0=0 & F1=1;

  Author: Anyes Taffard
*/

int main()
{
  unsigned int N;

  printf("How many terms? ");
  scanf("%u",&N);
  printf("Computing %u first terms of the Fibonacci sequence.\n",N);

  clock_t t = clock();
  
  /* Set the seeds */
  double Fn1 = 0;
  double Fn2 = 1;

  /* Special case of 0th term */
  if( N>0 ){ 
    printf("F[%3i] = %5.0f\n",0,0.);
  }
  /* Special case of 1st term */
  if( N>1 ){
    printf("F[%3i] = %5.0f\n",1,1.);
  }
  
  /* Generalisation */
  for( unsigned int i=2; i<N; i++ ){
    /* form the current term */
    double Fn = Fn1 + Fn2;
    double phi = ( i>=2) ? Fn / Fn2 : i;
    printf("F[%3i] = %5.0f \t %2.10f \n",i,Fn, phi);

    /* slide the terms */
    Fn1=Fn2;
    Fn2=Fn;
  }

  t = clock() - t;
  float sec = ((float) t)/CLOCKS_PER_SEC;
  printf("Excution times %d clicks (%f seconds) \n",(int) t, sec);
  
  return 0;
}


