#include <stdio.h>

int main() 
{
  double x = 0;
  int k;
  
  /* The wrong way to step through a real-valued variable */
  printf("The wrong way ! \n");
  for(x = 1.0; x > 0.0; x -= 0.1) {
    printf("loop 1: x = %.20f\n",x); /* %.20f requests 20 sig. digits */
  }
  
  /* The right way to do it */
  printf("\nThe right way ! \n");
  for(k = 10; k > 0; k--) {
    x = 0.1*k;
    printf("loop 2: x = %.20f\n",x);
  }
  
  return 0;
}
