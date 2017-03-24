#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Description: Example of opening/closing/reading file

  Author: Anyes Taffard
*/

int main(){
  FILE* fPtr;

  char fileName[] = "file2.dat";
  fPtr = fopen(fileName,"r");
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  
  char s[256];
  int iRead;
  printf("Reading from file %s \n",fileName);
  //read till reach End Of File
  while( fscanf(fPtr,"%s %i\n",s,&iRead) != EOF){ 
    printf("\t %s and %i\n",s,iRead);
  }
  
  //
  //Alternative way using fscanf
  //
  rewind(fPtr); //Got back to the start of the file
  printf("Alternative way to read from file %s \n",fileName);
  while( !feof(fPtr) ){
    char ss[256];
    int iiRead;
    fscanf(fPtr,"%s %i\n",ss,&iiRead);
    printf("\t %s and %i\n",ss,iiRead);
  }

  //
  //Alternative way to read a line of text using fgets 
  // note that fgets also read the \n at the end of the line.
  // If you don't want it, you need to remove it by hands
  //
  rewind(fPtr); //Got back to the start of the file
  printf("Alternative way to read line into a string for %s \n",fileName);
  char line[256]; //256 big enough to fit number of char per line
  while( fgets(line,sizeof(line), fPtr) != NULL ){   
    //printf("Read line %s\n",line);
    fputs ( line, stdout ); //alternative to printf
    //Removing the \n at the end of line
    char *rl;
    if ( (rl = strchr(line, '\n')) ) *rl = 0;
    printf("Read line %s\n",line);
  }


  fclose(fPtr);
  
  return 0;
}
