#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


/*
  Description: Shuffle inputs randomly.
  
  Author A. Taffard
*/

const int N = 1000;  //Numbers of entries in the file

/*
  Use Marsaglia's RNG 
*/
unsigned long long int v;
//_______________________________________________
unsigned long long int64() {
  v ^= v >> 21; v ^= v << 35; v ^= v >> 4;
  return v*2685821657736338717LL;
}
//_______________________________________________
void setSeed(unsigned long long int j) {
  v = 4101842887655102017LL;
  v ^= j;
  v = int64();
}
//_______________________________________________
double myRandom() {
  return 5.42101086242752217e-20*int64();
}

//__________________________________________________
int readData(char fileName[], int aSize, int array[])
{
  int nRead = 0;

  FILE* fPtr;
  fPtr = fopen(fileName,"r"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);

  while( !feof(fPtr) && nRead<aSize ){
    fscanf(fPtr,"%i ",&array[nRead++]);
  }
  
  printf("Read in %i numbers \n",nRead);
  fclose(fPtr);
  
  return nRead;
}
//__________________________________________________
void writeData(char fileName[], int aSize, int array[])
{
  FILE* fPtr;
  fPtr = fopen(fileName,"w"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);
  
  for(int i=0; i<aSize; i++){
    fprintf(fPtr,"%i \n",array[i]);
  }
  
  fclose(fPtr);
}

//__________________________________________________
void shuffle(int array[], int aSize)
{
  //Set random seed
  setSeed( time(NULL) * 391740128);
  
  for(int i=aSize-1; i>0; i--){
    //pick randomly a position in the array between [0,i)
    int iPick = floor(myRandom()*i);
    printf("Picked %i with %i remaining \n", iPick,i);
    
    //swap the picked element w/ the ith element
    int temp = array[iPick];
    array[iPick]=array[i];
    array[i] = temp;
  }

}
//__________________________________________________
//__________________________________________________
int main(){
  int array[N];
  
  int nRead = readData("shuffle_in.dat",N, array);
  if(nRead==0){
    printf("No data read\n");
    return -1;
  }

  shuffle(array, nRead);

  writeData("shuffle_out.dat",nRead, array);

  return 0;
}
