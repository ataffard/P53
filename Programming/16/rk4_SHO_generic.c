#include <stdio.h>
#include <math.h>

/*
  Description: Implementation of ODE's integration 
  via Runge-Kutta 4th order

  Simple Hamonic Oscillator with damping

  The version of this code is generic of a system of N ODE's

  Author: Anyes Taffard

*/

const double m = 1;   //mass [Kg]
const double k = 1;   //Spring constant [N/m]
const double b = 0.5; //damping coefficient

const int N = 2;      //dimension of the system of ODE 

//_________________________________________
/* Fills fvec[] with the derivatives of d vec[n]/dt 
   at the specified vec[n] values
   dx/dt = v
   dv/dt = - (b/m * v + k/m * x) 
*/
void ODE(double t, double vec[], double fvec[])
{
  fvec[0] = vec[1];
  fvec[1] = (-1.0) * (b/m * vec[1] +  k/m * vec[0]); 
}
//_________________________________________
/*
  Total Energy of the system. 
  Without damping, this is constant
*/
double E(double vec[])
{
  return 0.5 * m * pow(vec[1],2) + 0.5 * k * pow(vec[0],2);
}
//_________________________________________
/*
  Fills v[n] with c1*u1[n]+c2*u2[n] for 0 <= n < size.
*/
void addVectors(int size, double c1, double u1[], 
		double c2, double u2[], double v[]) 
{
  for(int i=0; i < size; i++) {
    v[i] = c1*u1[i] + c2*u2[i];
  }
}
//_________________________________________
/*
  Function to solve 1st order ODE 
  Method: 4th order Runge-Kutta
  
  Inputs:
  t: initial value for an independent variable
  h: step size
  vec: initial value of the ODE's 
  
  Output:
  vec: solution of the ODE after step h
  
*/
void rk4(double t, double h, int N, double vec[])
{
  double dydt1[N], dydt2[N], dydt3[N], dydt4[N]; //Evaluation of the ODE's
  double vec2[N], vec3[N], vec4[N];              //input value for ODE's evaluation

  //Estimate k1
  ODE(t, vec, dydt1);

  //Estimate k2
  addVectors(N, 1., vec, h/2.0, dydt1, vec2); //get new input points
  ODE(t+h/2.0, vec2,dydt2);
 
  //Estimate k3
  addVectors(N, 1., vec, h/2.0, dydt2, vec3); //get new input points
  ODE(t+h/2.0, vec3, dydt3);

  //Estimate k4
  addVectors(N, 1., vec, h, dydt3, vec4);     //get new input points
  ODE(t+h, vec4, dydt4);

  //Assemble the new points
  addVectors(N, 1, vec, h/6, dydt1, vec);
  addVectors(N, 1, vec, h/3, dydt2, vec);
  addVectors(N, 1, vec, h/3, dydt3, vec);
  addVectors(N, 1, vec, h/6, dydt4, vec);
}

//_________________________________________
//_________________________________________
int main(){
  
  double ti=0.0; //initial value of the independent variable
  /*
    yvec[0] represents x
    yvec[1] represents v
  */
  //Initialisation x0=0 and v0=1.
  double yvec[N];
  yvec[0] = 0.0;
  yvec[1] = 1.0;

  double dt   = 0.1; //step size [s]
  double tmax = 10;  //integrate from ti to tmax
  double tf=ti;
  printf("%lf %lf %lf %lf\n",ti,yvec[0],yvec[1],E(yvec));

  while(ti<tmax){
    tf += dt; //increment independent var
    
    rk4(ti, dt, N, yvec);

    printf("%lf %lf %lf %lf\n",tf,yvec[0],yvec[1],E(yvec));
    ti=tf;  //update for next step
  }
 
  return 0;
}
