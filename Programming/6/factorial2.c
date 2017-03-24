#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
  Description: Factorial example using function & for loop

  Author: Anyes Taffard
*/

/*
  Program gives correct answer for 1-12. 
  Try the following in google to understand what goes wrong above 12:
  12! in binary
  13! in binary
  log(12!)/log(2)
  log(13!)/log(2)
*/

//________________________________________________________
/* Iterative function to compute factorial */
int factorial(int k) {
  assert(k >= 1); 
  
  int result=1;
  for(; k>0; --k ) {
    result *= k;
  }
  
  return result;
}

//________________________________________________________
//________________________________________________________
int main() {
  int number;
  
  printf("Enter a number: ");
  scanf("%d",&number);
  
  printf("%d! = %d\n",number,factorial(number));
  
  return 0;
}
