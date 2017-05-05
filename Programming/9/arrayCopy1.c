/*
  Description: 2D array copy using loop

  Author: Anyes Taffard
*/
#include <stdio.h>
#include <time.h>

//C99 compiler allows for variable size array declaration, 
//however, it won't let you fix array dimension with a const var
//if you can initilize the array at compile time.
//That's because const var can still be changed using pointers.
//If the array is not initialized, using const int will compile 

//This will not compile, because table[NROW][NCOL] is initialized below.
//const int NCOL = 5;
//const int NROW = 5;

//Instead, declare the array dimension using the pre-processor define.
//At compilation time, all the instances of NROW and NCOL will be replaced
//by their respective value.
#define NROW 5
#define NCOL 5

//________________________________________
void printArray(int nRow, int nColumn, double array[][nColumn]){
  for(int iRow=0; iRow<nRow; iRow++){
    for(int iCol=0; iCol<nColumn; iCol++){
      printf("%lf \t",array[iRow][iCol]);
    }
    printf("\n");
  }
  return;
}

//________________________________________
//________________________________________
int main() {
  double table[NROW][NCOL] = { { 5.5, 4.6, 6.2,  0.3, 6.7 },
			       { 2.8, 1.43, 4.2,  6.8, 3.6 },
			       { 5.3, 7.9, 4.3, 21.2, 0.34 },
			       { 4.1, 8.5, 10.1, 15.8, 30.3 },
			       { 51.5, 17.6, 5.2, 1.8, 20.4 } };
  double tableCopy[NROW][NCOL];
  
  clock_t t = clock(); //Grab time
  //Copy array element one by one
  for(int iRow=0; iRow<NROW; iRow++){
    for(int iCol=0; iCol<NCOL; iCol++){
      tableCopy[iRow][iCol]=table[iRow][iCol];
    }
  }
  t = clock() - t; //get time difference
  
  //Print the copy
  printArray(NROW,NCOL,tableCopy);
  
  float sec = ((float) t)/CLOCKS_PER_SEC;
  printf("Execution times %d clicks (%f seconds) \n",(int) t, sec);
  
  return 0;
}
