#include <stdio.h>
#include <math.h>

/*
  Description: Implementation of ODE's integration 
  via Euler' method
  Simple Hamonic Oscillator

  Author: Anyes Taffard

*/

const double m = 1;  //mass [Kg]
const double k = 1;  //Spring constant [N/m]

//_________________________________________
// dx/dt = v
double f1(double t, double x, double v)
{
  double d1x = v; 
  return d1x;
}
//_________________________________________
// dv/dt = -x
double f2(double t, double x, double v)
{
  double d2x = (-1.0) * k/m * x; 
  return d2x;
}
//_________________________________________
double E(double m, double k, double x, double v)
{
  return 0.5 * m * v*v + 0.5 * k *x*x;
}

//_________________________________________
// xf = xi + h v(ti) 
// vf = vi + h dv/dt(ti) 
void euler(double ti, double xi, double vi,
	   double tf, double* xf, double* vf)
{
  *xf = xi + (tf-ti) * f1(ti, xi, vi);
  *vf = vi + (tf-ti) * f2(ti, xi, vi);  
}

//_________________________________________
//_________________________________________
int main(){

  double ti=0.0; //initial value of the independent variable
  double xi=0.0; //initial value of the function depending on t
  double vi=1.0; //initial value of the function depending on t


  double dt=0.01;//0.1; //step size [s]
  double tmax = 10; //integrate from ti to tmax

  double tf, xf, vf, Energy;
  tf=ti;
  xf=xi;
  vf=vi;
  Energy = E(m,k,xf,vf);
  printf("%lf %lf %lf %lf\n",tf,xf,vf,Energy);

  while(ti<tmax){
    tf += dt; //increment independent var
    euler(ti, xi, vi, tf, &xf, &vf);
    
    Energy=E(m,k,xf,vf);

    printf("%lf %lf %lf %lf\n",tf,xf,vf,Energy);
    ti=tf;  //update for next step
    xi=xf;
    vi=vf;
  }
  
  return 0;

}
