#include <stdio.h>

/*
  Description: Operators examples
  Author: Anyes Taffard
*/

int main()
{
  float a=1, b=2, c=3, d=10;
  int   e=15;
  
  a += 7;
  b -= 4;
  c *= 5;
  d /= 3;
  e %= 7;

  printf("a %f \n",a);
  printf("b %f \n",b);
  printf("c %f \n",c);
  printf("d %f \n",d);
  printf("e %i \n",e);
  
  int x = 5;
  int y = 10;

  int aX = ++x;
  printf("aX %i x %i\n",aX, x);
  
  int aY = y++;
  printf("aY %i y %i\n",aY, y);


  int i = 1;
  int j = 13;
  
  if( i==1 && j>= 10) printf("Here \n");
  if( i>=10 || j<= 2) printf("Here too \n");

  return 0;
}
