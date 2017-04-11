#include <stdio.h>

/*
  Description: Example for loop
               
  Author: Anyes Taffard
*/

int main() {   

  /* In C/C++ one can declare the var 
     to loop over inside the for condition
     Loops can be nested
  */
  
  for( int i=1; i<5; i++ ){
    for( int j=1; j<5; j++ ){
      printf("[%i,%i] \t", i, j);
    }
    printf("\n");
  }

  return 0;
}
