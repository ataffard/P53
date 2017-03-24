#include <stdio.h>

/*
  Description: Array example with day per month

  Author: Anyes Taffard
*/

int main() {
  /* Declare an array. The size must be a constant integer. */
  const int NMonths = 12;
  int daysPerMonth[NMonths];
  
  /* Initialize array values */
  daysPerMonth[0] = 31; /* indices start at zero so this is January */
  daysPerMonth[1] = 28; /* Feburary */
  /* ... */
  daysPerMonth[11] = 31; /* December */
  
  /* Array values can be used just like normal variables in an expression */
  double weeksInJanuary = daysPerMonth[0]/7.0;
  printf("January contains %f weeks\n",weeksInJanuary);
  
  return 0;
}
