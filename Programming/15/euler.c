#include <stdio.h>
#include <math.h>

/*
  Description: Implementation of ODE's integration 
  via Euler' method

  Author: Anyes Taffard

*/

//_________________________________________
double analyticSolution(double C, double t)
{
  return C*exp(t);
  //  return C*exp(-t);
}

//_________________________________________
double func(double t, double y)
{
  //double dy = (-1.0) * y; 
  double dy = y; 
  return dy;
}

//_________________________________________
double euler(double ti, double yi, double tf)
{
  double yf = yi + (tf-ti) * func(ti,yi);
  return yf;
}

//_________________________________________
//_________________________________________
int main(){

  double ti=0.0; //initial value of the independent variable
  double yi=1.0; //initial value of the function depending on t

  double dt=0.01;//0.01; //step size [s]
  double tmax = 2.5; //integrate from ti to tmax

  double tf, yf;
  tf=ti;
  yf=yi;
  printf("%lf %lf %lf \n",tf,yf,analyticSolution(yi,tf));

  while(ti<tmax){
    tf += dt; //increment independent var
    yf  = euler(ti, yf, tf);
    double sol = analyticSolution(yi,tf);
    double err = fabs(sol - yf)/sol;

    printf("%lf %lf %lf %f\n",tf,yf,sol,err);
    ti=tf;  //update for next step
  }
  
  return 0;

}
