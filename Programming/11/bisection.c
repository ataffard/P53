/*
  Description: Root finding using Bisection

  Author: Anyes Taffard
*/
#include<stdio.h>
#include <math.h>

const double EPS     = 1e-6;   //Define accuracy 
const int    MAXITER = 40;     //Allow up to 40 iterations. 
                               //After ~40 reach machine accuracy 
                               //for double precision


//____________________________________________________
//  Function we want to find the root
double F(double x){
  //return pow(x,3) + pow(x,2) + x - 7;  //1 root ~1.5
  //return x*x - 4 * sin(x);             //2 root ~0 & ~1.9
  //return 2 * sin(x) - x*x - exp(-x);   //2 roots [0,1]=>~0.4, [1,2]=>~1.3
  //return x*x;                          //No change af sign - cannot find bracket
  //return 1/(x-1);                      //No root. Singularity ~1
  return 3*x+sin(x) -exp(x);             //[0,1]=> ~0.36
  //return x-cos(x);                     //Range [0-4]=>~0.7
}
//____________________________________________________
//____________________________________________________
int main()
{
  int iter = 1;
  double x0,x1,x2;
  double f0,f1,f2;
  
  // Request from user the initial guess bracket to start from.
  // Check that the guess is valid ... otherwise, keep asking
  int valid =0;
  while(!valid){
    printf("\nEnter the first approximatiom of the root (x0): ");
    scanf("%lf",&x0);
    printf("\nEnter the second approximation of the root (x1): ");
    scanf("%lf",&x1);
    
    f0=F(x0);      
    f1=F(x1);
    
    if(f0*f1<0) valid =1;
    else {
      printf("\n Initial guess is not valid\n");
      printf("f(x0)=%f \n",f0);
      printf("f(x1)=%f \n",f1);
    }
  }

  printf("\nIter\t\t x0 \t x1 \t x2 \t f0 \t f1 \t f2 \n");
  do {
    x2=x0+(x1-x0)/2;  //evaluate mid point. Equiv to (x0+x1)/2 but better for accuracy.
    f0=F(x0);         //evaluate function at x0, x1, x2
    f1=F(x1);
    f2=F(x2);
    printf("%d \t %+f %+f %+f %+lf %+lf %+lf\n", iter, x0,x1,x2, f0,f1,f2);
    if(f0*f2<0) x1=x2;
    else        x0=x2;
    iter++;
  } while(fabs(x0-x1)>=EPS && fabs(f2)>EPS && iter<MAXITER);
  //safer. Works for function w/ singularity
 
  printf("\n__________________________________________________________\n");
  if(iter>=MAXITER){
    printf("Could not find root after %i iterations",iter);
    printf("Try other starting bracket values. \n");
  }
  else
  printf("\n\nRoot = %f\n",x2);

  return 0;
}
