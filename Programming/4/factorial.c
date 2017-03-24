#include <stdio.h>

/*
  Description: Factorial example
  eg 5! = 5 * 4 * 3 * 2 * 1 = 120
  
  Author: Anyes Taffard
*/

int main() 
{
  
  /* Declare the variables we will use */
  int n,result;
  
  /* Ask the user for a number */
  printf("Enter a non-negative number: ");
  scanf("%d",&n);
  
  /* Check the input */
  if(n < 0) {
    printf("I said non-negative!\n");
    return -1;
  }
  else {
    /* Calculate the factorial */
    result = 1;
    int k;
    for(k = 1; k <= n; k++) {
      result = result*k;
    }
    /* Print the result */
    printf("The factorial of %d is %d\n",n,result);
  }
  
  return 0;
}
