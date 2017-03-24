#include <stdio.h>

/*
  Description: Array example out-of-bound

  Author: Anyes Taffard
*/

int main() {
  double vector[3];
  double pi = 3.141;
  
  printf("pi = %f\n",pi);
  
  /* A demonstration of what can go wrong 
     if you accidentally refer to a
     non-existent array element... */
  vector[3] = -1.23;
  printf("pi = %f\n",pi);
  
  return 0;
}
