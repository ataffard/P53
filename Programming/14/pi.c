#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <time.h>

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
double monteCarloPi(int ntrials) {
    int nhit = 0;
    double min = -1;
    double max =  1;
    for(int i=0; i<ntrials; i++) {
      //generate a random point (x,y) in the unit square
      double x = min + (max-min) * myRandom();
      double y = min + (max-min) * myRandom();
      //test if (x,y) is within an inscribed circle
      if( sqrt(x*x+y*y) < 1) nhit++;
    }
    //convert the hit fraction to an estimate of pi
    return (4.*nhit)/ntrials;
}
//_________________________________________
//_________________________________________
int main(){
  //Set random seed
  setSeed( time(NULL) * 391740128);
  
  int N = 1000000;
  
  //Gradually increase ntrials with logarithmic spacing
  int ntrials = 10;			       
  double I=0;
  do {
    I = monteCarloPi(ntrials);
    //calculate and print residuals 
    printf("%d %lf\n",ntrials,fabs(I-M_PI));
    ntrials = (int)ceil(1.02*ntrials);
  } while(ntrials < N);
  
  printf("Computed Pi %lf \n",I);
  return 0;
}
