#include <stdio.h>

/*
  Description: Switch operator
  Author: Anyes Taffard
*/

int main()
{
  int x = 3;

  switch (x) {
  case 1:
    printf("x is 1 \n");
    break;
  case 2:
    printf("x is 2 \n");
    break;
  case 3:
    printf("x is 3 \n");
    break;
  default:
    printf("The value of x is %i \n",x);
    break
  }

  return 0;
}
