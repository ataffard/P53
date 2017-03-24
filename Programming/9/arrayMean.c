#include <stdio.h>
#include <stdlib.h>
/*
  Description: Return mean of 2 columns stored in a file
  
  Author: Anyes Taffard
*/
const int NLINES=1000;

//________________________________________
double mean(int sizeN, double array[]){
  double sum = 0;
  for(int i=0; i<sizeN; i++){
    sum+=array[i];
  }
  return sum/sizeN;
}

//________________________________________
//________________________________________
int main() {
  FILE* fPtr;

  char fileName[] = "arrayMean.dat";
  fPtr = fopen(fileName,"r"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }

  double x[NLINES];
  double y[NLINES];

  //Read file up to NLINES max
  int iLines=0;
  while( !feof(fPtr) && iLines<NLINES ){
    fscanf(fPtr,"%lf %lf",&x[iLines],&y[iLines]);
    iLines++;
  }
  iLines--; //-1 to remove the line w/ EOF
  fclose(fPtr);

  //Print the mean of each column
  printf("Read %i lines \n",iLines);
  printf("Column 1 mean is: %f \n",mean(iLines, x));
  printf("Column 2 mean is: %f \n",mean(iLines, y));

  return 0;
}
