#include <stdio.h>

/*
  Description: 2D array example 

  Author: Anyes Taffard
*/

int main() {
  /* Declare an array. The size must be a constant integer. */
  int a[3][5] = {{0}}; //initialize all the elements to 0

  int b[] = {3, 6, 2, 8, 9};
  for(int i=0; i<5; i++){
    printf("b[%i]=%i\n",i,b[i]);
  }

  int table[3][5] = { { 5, 4, 6,  0, 6 },
		      { 2, 1, 4,  6, 3 },
		      { 5, 7, 4, 21, 0 } };

  for(int iRow=0; iRow<3; iRow++){
    for(int iCol=0; iCol<5; iCol++){
      printf("%i \t",table[iRow][iCol]);
    }
    printf("\n");
  }
  
  return 0;
}
