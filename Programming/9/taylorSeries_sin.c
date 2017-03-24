#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  Description: Compute 1st N term of a Taylor series for sin(x)
  with x=[-10,10] in step of 0.05.
  Output save to file to compare TS to sin(x) using gnuplot

  Author: Anyes Taffard
*/

const float STEP=0.05;  //Step size
const float RANGE=10.0; //Range -> +/-

const int debug = 0;

//Compute taylor expention of sin(x)
double taylorSerieSin(double x, int n);

//__________________________________________________
//__________________________________________________
int main(){
  int  number;
  
  printf("Enter the number of step: ");
  scanf("%i",&number);
  printf("\n");

  FILE* fPtr;

  char fileName[] = "taylorSeries_sin.dat";
  fPtr = fopen(fileName,"a");
  
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }

  fprintf(fPtr,"#\n");
  fprintf(fPtr,"# Using N %i steps \n",number);
  fprintf(fPtr,"#\n");
  fprintf(fPtr,"# x \t sin(x) \t TS sin(x) \t delta\n");
  fprintf(fPtr,"#\n");

  int iEnd = RANGE/STEP;
  int iStart = -iEnd;

  for(int i=iStart; i<=iEnd; i++){
    double x = i*STEP;
    double sinX   = taylorSerieSin(x,number);
    fprintf(fPtr,"%lf %lf %lf\n",x,sinX,sinX-sin(x));
  }
  fprintf(fPtr,"\n\n");
  
  fclose(fPtr);

  return 0;
}


//__________________________________________________
// counting down is more accurate
double taylorSerieSin(double x, int n){
  double res   = 0;
  double pow   = x;
  double frac  = 1;
  
  for(int i=0; i<n; i++){
    res  += pow*frac;
    if(debug) printf(" res %2.4f pow %2.4f frac %2.4f \n",res, pow, frac);
    //prepare next term
    pow  *= x*x;
    float denom = (2*(i+1)) * (2*(i+1) +1) ;
    frac *= -1.0 /denom;
    if(debug) printf("\t pow %2.3f denom %2.3f frac %2.6f next %2.4f\n",
		     pow, denom, frac, pow*frac);
  }

  return res;
}

