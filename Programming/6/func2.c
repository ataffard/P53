#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
  Description: Simple function example

  Author: Anyes Taffard
*/
//____________________________________________
void call_by_value(int i){
  printf("\tInside call_by_value before a=%d \n",i);
  i += 10;
  printf("\tInside call_by_value after a=%d \n",i);
}

//____________________________________________
void call_by_reference(int *i){
  printf("\tInside call_by_value before a=%d \n",*i);
  *i += 10;
  printf("\tInside call_by_value after a=%d \n",*i);
}

//____________________________________________
//____________________________________________
int main(){
  int a = 10;

  printf("Inside main, before call_by_value a=%d \n",a);
  call_by_value(a);
  printf("Inside main, after call_by_value a=%d \n\n",a);

  printf("Inside main, before call_by_reference a=%d \n",a);
  call_by_reference(&a);
  printf("Inside main, after call_by_reference a=%d \n",a);

  return 0;
}
