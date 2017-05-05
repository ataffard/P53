#include <stdio.h>

/*
  Description: Example of trace and transpose for matrix

  Author: Anyes Taffard
*/

#define NSIZE 3

//__________________________________________
void printArray(int nRow, int nColumn, float array[][nColumn]){
  for(int iRow=0; iRow<nRow; iRow++){
    for(int iCol=0; iCol<nColumn; iCol++){
      printf("%2.2f \t",array[iRow][iCol]);
    }
    printf("\n");
  }
  return;
}
//__________________________________________
//__________________________________________
int main() {
  //
  // Calculate trace of matrix
  //   T = Sum(x_ii) 
  //
  float matrix[NSIZE][NSIZE] = { {-2, 5,  1},
				 { 3, 4,  9},
				 {-1, 2, -5} };
  printf("The matrix is: \n");
  printArray(NSIZE,NSIZE,matrix);
  printf("\n");

  float trace = 0;
  for(int i=0; i<NSIZE; i++){
    trace += matrix[i][i];
  }
  printf("The trace is %2.2f\n\n",trace);
  
  //
  // Transpose the array
  //   [A^T]_{ij} = [A]_{ji} 
  //   swap the i rows, j columns to
  //   j rows, i columns
  //
  for (int i=0;i<NSIZE;i++) {
    for (int j=i+1;j<NSIZE;j++){
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i]; //i,j <-- j,i 
      matrix[j][i] = temp;         //j,i <-- i,j (from temp)
    }
  }
  printf("The transpose is: \n");
  printArray(NSIZE,NSIZE,matrix);
  return 0;
}
