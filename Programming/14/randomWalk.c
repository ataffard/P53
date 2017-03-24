#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
  Description: Simulate random walker
  Eg: steps 500 nWalkers = 1
  Author Anyes Taffard
*/

const int debug = 1;

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

//_________________________________________
//_________________________________________
int main()
{
  int nSteps;
  int nWalkers;
  
  printf("Enter the number of steps: ");
  scanf("%d",&nSteps);
  
  printf("Enter the number of walkers: ");
  scanf("%d",&nWalkers);
  
  //Set random seed
  setSeed( time(NULL) * 391740128);
  
  //Open output file
  FILE* fPtr;
  char fileName[] = "randomWalk.dat";
  fPtr = fopen(fileName,"w"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);


  int x=0;
  int y=0;
  int iWalker=0;
  fprintf(fPtr,"%i \t %i\n",x,y);
  while(iWalker < nWalkers){
    for(int i=0; i<nSteps; i++){
      double RN=myRandom();  
      if      (RN < 0.25)  x++;   // step East
      else if (RN < 0.50)  y++;   // step North
      else if (RN < 0.75)  x--;   // step West
      else                 y--;   // step South
      fprintf(fPtr,"%i \t %i\n",x,y);
    }
    iWalker++;
  }


  fclose(fPtr);

  return 0;
}
