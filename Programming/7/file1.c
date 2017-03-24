#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Description: Example of opening/closing file

  Author: Anyes Taffard
*/

int main(){
  FILE* fPtr;

  char fileName[] = "file1.dat";
  fPtr = fopen(fileName,"w");
  
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
 
  /* do something */

  fclose(fPtr);

  return 0;
}
