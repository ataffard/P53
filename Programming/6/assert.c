#include <stdio.h>
#include <assert.h>

/*
  Description: Assert example

  Author: Anyes Taffard
*/

int main() {
  /* Get an integer from the user */
  int anInteger;

  printf("Enter an integer: ");
  scanf("%d",&anInteger);
  assert(anInteger != 0);
  
  /* Try to take its reciprocal */
  int reciprocal = 1/anInteger;
  printf("1/%d = %d\n",anInteger,reciprocal);
  
  return 0;
}
