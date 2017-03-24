#include <stdio.h>
#include <math.h>

/*
  Description: Example passing array to function
  
  Author: Anyes Taffard
*/

/*
  The commented lines are an alternative 
  notation for doing the same thing
*/

//Compute the instantaneous velocity for each d/t intervals
void getSpeed(float d[], float t[], float s[], int nElements);
//void getSpeed(float *d, float *t, float *s, int nElements);

//____________________________________________________
//____________________________________________________
int main(){
  const int nEntries = 6;

  float distance[] = {3, 6, 13, 9, 13, 18};          //distance intervals
  float time[]     = {0.2, 0.4, 0.3, 0.5, 0.6, 0.2}; //time interval
  float speed[6]   = {0.0};

  getSpeed(distance, time, speed, nEntries);
  //getSpeed(&distance[0], &time[0], &speed[0], nEntries);

  for(int i=0; i<nEntries; i++){
    printf("v[%i] = %f\n",i,speed[i]); 
  }

  return 0;
}

//____________________________________________________
void getSpeed(float d[], float t[], float s[], int nElements){
  //void getSpeed(float *d, float *t, float *s, int nElements){

  for(int i=0; i<nElements; i++){
    if(fabs(t[i]) < 1e-10){
      s[i]=0; 
      continue; 
    }
    s[i] = d[i] / t[i];  
  }
}
