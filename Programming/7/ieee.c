#include <stdio.h>
#include <math.h>

/*
  Description: Floating point arithmetics
  Note C does not have booleans's

  Author: Anyes Taffard
*/

int main() {
  
  /* Divide by zero */
  double big = 1.0/0.0;
  printf("big = %f\n",big);
  
  /* A variation on divide by zero */
  double negbig = -1.0/0.0;
  printf("negbig = %f\n",negbig);
  
  /* Do they cancel each other out? */
  double bigsum = big + negbig;
  printf("bigsum = %f\n",bigsum);
  
  /* Other ways to get not-a-number (nan) */
  double nan1 = log(-1.0);
  printf("nan1 = %f\n",nan1);
  
  double nan2 = asin(2.0);
  printf("nan2 = %f\n",nan2);
  
  double nan3 = 0.0/0.0;
  printf("nan3 = %f\n",nan3);
  
  /* Are all nan's the same? */
  int same12 = (nan1 == nan2);
  int same13 = (nan1 == nan3);
  int same23 = (nan2 == nan3);
  printf("nan1 == nan2 ? %d\n",same12);
  printf("nan1 == nan3 ? %d\n",same13);
  printf("nan2 == nan3 ? %d\n",same23);

  int   x = 33554431;
  float y = 33554431;
  printf("x:%d\n",x);
  printf("y:%f\n",y);
  

  return 0;
}
