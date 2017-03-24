#include <stdio.h>

/*
  Description: Simple example using pointer

  Author: Anyes Taffard
*/

//____________________________________________
//____________________________________________
int main(){
  int x;              // a variable
  int *xPtr = NULL;   // a pointer

  x = 10; 
  printf(" x = %d \n",x);
  
  xPtr = &x;         // assign address of x to xPtr (xPtr->x)
  printf(" xPtr points to variable of value = %d \n\n",*xPtr);

  printf("Set xPtr = 20 \n");
  *xPtr = 20;        //sets x to 20 via the xPtr pointer
  printf(" xPtr points to variable of value = %d \n",*xPtr);
  printf(" x = %d \n\n",x);

  
  printf("Set x = 30 \n");
  x = 30;            // change the value of x
  printf(" x = %d \n",x);  
  printf(" xPtr points to variable of value = %d \n",*xPtr);

  return 0;
}
