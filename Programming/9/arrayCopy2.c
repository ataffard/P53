#include <stdio.h>
#include <string.h>

/*
  Description: 2D array copy using memcpy

  Author: Anyes Taffard
*/


void printArray(int nRow, int nColumn, int array[][nColumn]){
  for(int iRow=0; iRow<nRow; iRow++){
    for(int iCol=0; iCol<nColumn; iCol++){
      printf("%i \t",array[iRow][iCol]);
    }
    printf("\n");
  }
  return;
}

//________________________________________
//________________________________________
int main() {

  int table[3][5] = { { 5, 4, 6,  0, 6 },
		      { 2, 1, 4,  6, 3 },
		      { 5, 7, 4, 21, 0 } };

  int tableCopy[3][5];

  memcpy(tableCopy, table, sizeof(tableCopy));
  printArray(3,5,tableCopy);

  return 0;
}
