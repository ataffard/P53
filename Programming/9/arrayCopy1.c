#include <stdio.h>

/*
  Description: 2D array copy using loop

  Author: Anyes Taffard
*/

int main() {

  int table[3][5] = { { 5, 4, 6,  0, 6 },
		      { 2, 1, 4,  6, 3 },
		      { 5, 7, 4, 21, 0 } };

  int tableCopy[3][5];

  //Copy array element one by one
  for(int iRow=0; iRow<3; iRow++){
    for(int iCol=0; iCol<5; iCol++){
      tableCopy[iRow][iCol]=table[iRow][iCol];
    }
  }
  
  //Print the copy 
  for(int iRow=0; iRow<3; iRow++){
    for(int iCol=0; iCol<5; iCol++){
      printf("%i \t",tableCopy[iRow][iCol]);
    }
    printf("\n");
  }

  return 0;
}
