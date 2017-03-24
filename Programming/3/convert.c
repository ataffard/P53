#include <stdio.h>
#include <math.h>

/*
  Description: Conversion examples

  Author: Anyes Taffard
*/

int main() {
  /* Conversion from int to double is unambiguous */
  int three = 3;
  double pi = three;    
  printf("Three %i PI %f\n",three, pi);

  /* Conversion from double to int is ambiguous */
  double number;
  printf("Enter a decimal number: ");
  scanf("%lf",&number);
  
  /* A direct cast throws away the fractional part of the number */
  printf("(int)number = %d\n",(int)number);
  
  /*
    The floor/ceil/round functions return a double with no fractional part
    in a controlled and predictable way. You still need to convert the
    result to an integer with (int).
  */
  printf("(int)floor(number) = %d\n",(int)floor(number));
  printf("(int)ceil(number) = %d\n",(int)ceil(number));
  printf("(int)round(number) = %d\n",(int)round(number));

  return 0;
}
