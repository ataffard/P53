/*
  Description: Example if, else if, else condition
               
  Author: Anyes Taffard
*/
#include <stdio.h>

int main() {   
  int a;
  
  printf("Type an integer: ");
  scanf("%d",&a);

  if(a > 5){
    printf("a > 5 \n");
  }
  else if ( a < 2){
    printf("a < 2 \n");
  }
  else {
    printf("a not < 2 and > 5  \n");
  }

  return 0;
}
