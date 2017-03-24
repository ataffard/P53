#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
  Description: Power function example using recursive function

  Author: Anyes Taffard
*/
/* Recursive function to compute x^n */
double power(double x, int n);

//__________________________________________________
//__________________________________________________
int main() {
  double x;
  int n;
  
  printf("Enter a double x = ");
  scanf("%lf",&x);
  printf("Enter a interger n = ");
  scanf("%d",&n);
  
  printf("x^n:  %f^(%d) = %f\n",x,n,power(x,n));
  
  return 0;
}

//__________________________________________________
/* Recursive function to compute x^n */
double power(double x, int n) {
  if(n == 0) {
    return 1;
  }
  else if ( n>0 ) {
    return x*power(x,n-1);
  }
  else {
    assert( fabs(x) > 1e-20 );
    return 1/x * power(x,n+1);
  }
}
