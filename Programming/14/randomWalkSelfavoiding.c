#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/*
  Description: Simulate random walker
  Self avoidance

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
  printf("Enter the number of steps: ");
  scanf("%d",&nSteps);
  
  //Set random seed
  setSeed( time(NULL) * 391740128);
  
  //Open output file
  FILE* fPtr;
  char fileName[] = "randomWalkSelfavoiding.dat";
  fPtr = fopen(fileName,"w"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);

  int grid[1000][1000];
  memset(grid,0,sizeof(grid[0][0])*1000*1000); 

  int x=0;
  int y=0;
  int xold = x;
  int yold = y;

  grid[0][0]=1;
  fprintf(fPtr,"%i \t %i\n",x,y);

  for(int i=0; i<nSteps; i++){
    double RN=myRandom(); 
    x=xold;
    y=yold;
    if      (RN < 0.25)  x++;   // step East
    else if (RN < 0.50)  y++;   // step North
    else if (RN < 0.75)  x--;   // step West
    else                 y--;   // step South

    //If walker goes out of bound - stay in position
    if(x>1000) continue;
    if(y>1000) continue;

    //Skip if been there before
    if(grid[x][y]==1) continue;
    else{ //update position
      grid[x][y]=1;
      fprintf(fPtr,"%i \t %i\n",x,y);
      xold=x;
      yold=y;
    }
  }

  fclose(fPtr);

  return 0;
}
