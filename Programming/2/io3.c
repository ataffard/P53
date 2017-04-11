#include <stdio.h>

/*
  Description: Example using printf and scanf
  stdio.h is a c header

  Author: Anyes Taffard
*/

int main()
{
  int integer;
  double floatingpoint;
  char characters[10];

  //Get input data from user
  printf("Type an integer: ");
  scanf("%i",&integer);

  printf("Type a double: ");
  scanf("%lf",&floatingpoint);

  printf("Type a string:");
  scanf("%s",characters);

  //Print back data
  printf("Integer: %i \nfloatp: %f \nchars: %s \n",integer,floatingpoint, characters);

  return 0;
}
