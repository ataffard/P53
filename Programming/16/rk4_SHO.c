#include <stdio.h>
#include <math.h>

/*
  Description: Implementation of ODE's integration 
  via Runge-Kutta 2nd and 4th order

  Simple Hamonic Oscillator (with or without damping)

  Author: Anyes Taffard
*/

const double m = 1;   //mass [Kg]
const double k = 1;   //Spring constant [N/m]
const double b = 0.5; //damping coefficient

//_________________________________________
// dx/dt = v  (1st order derivative)
double f1(double t, double x, double v)
{
  double d1x = v; 
  return d1x;
}
//_________________________________________
// dv/dt = -x  (1st order derivative)
double f2(double t, double x, double v)
{
  //  double d2x = (-1.0) * k/m * x;  //No damping
  double d2x = (-1.0) * ( b/m * v + k/m * x); //With damping
  return d2x;
}
//_________________________________________
/*
  Total Energy of the system. 
  Without damping, this is constant
*/
double E(double m, double k, double x, double v)
{
  return 0.5 * m * v*v + 0.5 * k *x*x;
}
//_________________________________________
/*
  Function to solve 1st order ODE 
  Method: 2nd order Runge-Kutta
  
  Inputs:
  ti: initial value for an independent variable (t)
  xi: initial value of x(t)
  vi: initial value of x'(t)
  tf: find the solution at the point
  
  Outputs:
  xf, vf: solution at point tf ie x(tf) and x'(tf)
  
*/
void rk2(double ti, double xi, double vi,
	 double tf, double* xf, double* vf)
{
  double k1x, k2x;
  double k1v, k2v;

  double h = tf - ti;
  double t = ti;

  k1x = f1(t, xi, vi);
  k1v = f2(t, xi, vi);

  k2x = f1(t+h, xi+h*k1x, vi+h*k1v);
  k2v = f2(t+h, xi+h*k1x, vi+h*k1v);

  *xf = xi + (k1x + k2x) * h/2.0;
  *vf = vi + (k1v + k2v) * h/2.0;
}
//_________________________________________
/*
  Function to solve 1st order ODE 
  Method: 4th order Runge-Kutta
  
  Inputs:
  ti: initial value for an independent variable (t)
  xi: initial value of x(t)
  vi: initial value of x'(t)
  tf: find the solution at the point
  
  Outputs:
  xf, vf: solution at point tf ie x(tf) and x'(tf)
  
*/
void rk4(double ti, double xi, double vi,
	 double tf, double* xf, double* vf)
{
  double k1x, k2x, k3x, k4x;
  double k1v, k2v, k3v, k4v;

  double h = tf - ti;
  double t = ti;

  k1x = h*f1(t, xi, vi);
  k1v = h*f2(t, xi, vi);

  k2x = h*f1(t+h/2.0, xi+k1x/2.0, vi+k1v/2.0);
  k2v = h*f2(t+h/2.0, xi+k1x/2.0, vi+k1v/2.0);

  k3x = h*f1(t+h/2.0, xi+k2x/2.0, vi+k2v/2.0);
  k3v = h*f2(t+h/2.0, xi+k2x/2.0, vi+k2v/2.0);

  k4x = h*f1(t+h, xi+k3x, vi+k3v);
  k4v = h*f2(t+h, xi+k3x, vi+k3v);

  *xf = xi + (k1x + 2.0*(k2x+k3x) + k4x)/6.0;
  *vf = vi + (k1v + 2.0*(k2v+k3v) + k4v)/6.0;

}

//_________________________________________
//_________________________________________
int main(){
  
  double ti=0.0; //initial value of the independent variable
  double xi=0.0; //initial value of the function depending on t
  double vi=1.0; //initial value of the function depending on t
  
  double dt=0.1;    //step size [s]
  double tmax = 10; //integrate from ti to tmax

  double tf, xf, vf;
  tf=ti;
  xf=xi;
  vf=vi;
  printf("%lf %lf %lf %lf\n",tf,xf,vf,E(m,k,xf,vf));

  while(ti<tmax){
    tf += dt; //increment independent var

    //rk2(ti, xi, vi, tf, &xf, &vf);
    rk4(ti, xi, vi, tf, &xf, &vf);

    printf("%lf %lf %lf %lf\n",tf,xf,vf,E(m,k,xf,vf));
    ti=tf;  //update for next step
    xi=xf;
    vi=vf;
  }
  
  return 0;
}
