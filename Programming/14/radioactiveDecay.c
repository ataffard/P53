#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
  Description: Simulate radiactive decay by Monte Carlo simulation
  eg test tmax=20s for 5k sample size, tau = 5s

  Author Anyes Taffard
*/

const int debug = 0;
const double dt = 0.01; //time interval 0.01s to check how many nuclei left

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
  int tmax, N0, tau;

  printf("Enter the maximum time (sec): ");
  scanf("%d",&tmax);
  printf("Enter the initial number of nuclei: ");
  scanf("%d",&N0);
  printf("Enter the mean lifetime (tau s): ");
  scanf("%d",&tau);

  printf("--------------------------------------------------\n");
  double lambda = 1./(double) tau;  //inverse of the mean lifetime (eg tau = 5s)

  //Set random seed
  setSeed( time(NULL) * 391740128);

  //Open output file
  FILE* fPtr;
  char fileName[] = "radioactiveDecay.dat";
  fPtr = fopen(fileName,"w"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);

  
  int NLeft=N0; //initialisation
  double t1=0;
  fprintf(fPtr,"###########################\n");
  fprintf(fPtr,"# t(s)\tN(t)\n");
  fprintf(fPtr,"%.2f\t%d\n",t1,NLeft);
  
  int i=0; //counter for printout
  while(t1<=tmax && NLeft>0){
    t1+=dt;
    i++;
    for(int j=0; j<=N0; j++){ //randomly decay nuclei
      double RN=myRandom();  
      if(RN<(lambda*dt)){
	NLeft--;
	if(debug) 
	  printf("\t Decay nuclei RN %lf NLeft %i t1 %lf \n",RN, NLeft, t1);
      }
    }
    N0=NLeft;//update how many non-decayed nuclei left
    if(i%10==0) { //print to file every 1/10 seconds
      fprintf(fPtr,"%.2f \t %d\n",t1,NLeft);
      i=0;
    }
  }

  fclose(fPtr);
  
  return 0;
}
