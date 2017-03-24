#include <stdio.h>

/*
  Description: Example of bad loops !
  Use ctrl^C to kill executable

  Author: Anyes Taffard
*/


int main() {

  /* A loop that never executes */
  int i;
  for(i = 0; i < 0; i++) {
    printf("loop 1: i = %d\n",i);
  }
  
  /* An infinite loop */
  int j;
  for(j = 0; j >= 0; j++) {
    printf("loop 2: j = %d\n",j);
  }
  
  return 0;
}
