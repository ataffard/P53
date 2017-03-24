#include <math.h>
#include <stdio.h>
#include <assert.h>

/*
  Description: example of solving PDE
  Heat diffusion equation: cooking a turkey

  Author: Anyes Taffard

*/

int main() {
  double tmax  = 5*60*60;  // 5 hours in seconds
  double rmax  = 15;       // radius cm 
  double konst = 2e-3;     // thermal diffusion cm^2/s 
  
  // Temperatures in degrees F 
  double T1 = 75;   //initial temperature
  double T2 = 400;  //oven temperature
  double T3 = 170;  //cooked bird temperature
  
  int Nt = 1000, Nr = 50;
  double Temp[1000][1000]; // 1st dimension: radius, 2nd dimension: dt step
  
  double dt = tmax/Nt;  //time increment
  double dr = rmax/Nr;  //radial distance /space increment
  konst *= dt/(dr*dr);
  printf("# konst = %lf\n",konst);
  
  int halfhour = (int)floor(30.*60./dt);
  
  // Define initial state
  // Set the whole object to same temperature
  for(int k = 0; k < Nr; k++) {
    Temp[k][0] = T1;
  }
  
  for(int n = 0; n < Nt; n++){
    for(int k = 1; k < Nr-1; k++) {
      double delta = (k+1.)/k*Temp[k+1][n]-2*Temp[k][n]+(k-1.)/k*Temp[k-1][n];
      Temp[k][n+1] = Temp[k][n] + konst*delta;
    }
    
    /* Calculate Temp(rmax,t) 
       Boundary conditions
    */
    double elapsed = dt*n;
    if(elapsed < 60.*60.) { 
      Temp[Nr-1][n+1] = T2;
    }
    else {
      Temp[Nr-1][n+1] = T3;//After 1hr, the outer part reach temp goal 
    }
    
    // Temp(0,t) is fixed by no conduction condition
    Temp[0][n+1] = Temp[1][n+1];

    // Periodic printout
    if((n+1) % halfhour == 0) {
      printf("\n\n");
      for(int k = 0; k < Nr; k++) {
	printf("%lf %lf\n",k*dr,Temp[k][n+1]);
      }
    }
  }

  return 0;
}
