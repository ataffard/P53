#include <stdio.h>

/*
  Description: Calculate the mean between two input numbers

  Author: Anyes Taffard
*/
int main() {
  /* Declare the variables we will use */
  double number1, number2, mean;
  
  /* Get a pair of numbers from the user */
  printf("Enter two numbers: "); /* notice that we omit the end-of-line character '\n' */
  scanf("%lf %lf", &number1, &number2);
  
  /* Calculate their mean and show the result */
  mean = 0.5 * ( number1 + number2 );
  printf("The mean of %f and %f is %f\n", number1, number2, mean);

  return 0;
}
