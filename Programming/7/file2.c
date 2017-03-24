#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Description: Example of opening/closing/writing file

  Author: Anyes Taffard
*/

int main(){
  FILE* fPtr;

  char fileName[] = "file2.dat";
  fPtr = fopen(fileName,"w");
  
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  
  for(int i=0; i<10; i++){
    fprintf(fPtr,"Number: %i\n",i);
  }
  
  fclose(fPtr);
  
  return 0;
}
