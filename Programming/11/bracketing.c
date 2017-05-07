/*
  Description: Bracketing algorithms from Numerical Methods

  Author: Anyes Taffard
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FACTOR 1.6
#define NTRY   50

const int dbg = 1; //set to 1 to debug
//____________________________________________________
//  Given function and initial guessed interval [a.b], 
//  expands range until root is bracketed.
//  Return 1 if valid range found, else 0
int zbrac(double (*f)(double), double *a, double *b);

//____________________________________________________
//  Given function and an initial interval [a,b], 
//  subdivide interval into n equal segments, 
//  and search for the zero crossings of the function.
//  nrmax is the maxumin number of roots sought.
void zbrak(double (*f)(double), double a, double b,
	   int n, double xlow[], double xhigh[], int *nrmax);


//____________________________________________________
// Bunch of functions
double F1(double x); //x^3 + x^2 + x - 7         -- 1 root ~1.5
double F2(double x); //x^2 - 4sin(x)             -- 2 root ~0 & ~1.9
double F3(double x); //2sin(x) -x^2 -e^(-x)      -- 2 roots [0,1]=0.4, [1,2]=1.3
double F4(double x); //x^2                       -- No change af sign - cannot find bracket
double F5(double x); //1/(x-1)                   -- No root. Singularity ~1

//____________________________________________________
//Swap the content of a & b if a>b
void swap(double* a, double* b);

//____________________________________________________
//____________________________________________________
int main()
{
  int valid =0;
  int function;

  //------------------------------
  // Step 1: Choose the function
  //------------------------------
  while(!valid){
    printf("Choose function\n");
    printf("[1]: x^3 + x^2 +x +7\n");
    printf("[2]: x^2 - 4sin(x)\n");
    printf("[3]: 2sin(x) -x^2 -e^(-x)\n");
    printf("[4]: x^2\n");
    printf("[5]: 1/(x-1)\n");

    scanf("%i",&function);
    if(function>=1 && function<=5) valid=1;
  }

  double (*func)(double); //declare pointer to a function which as a double as argument
  switch(function){
  case 1:
    func = *F1;
    break;
  case 2:
    func = *F2;
    break;
  case 3:
    func = *F3;
    break;
  case 4:
    func = *F4;
    break;
  case 5:
    func = *F5;
    break;
  default:
    break;
  }

  //-------------------------------------------------------
  // Step 2: Choose the bracketing method & print results
  //-------------------------------------------------------
  int method;
  valid =0;
  while(!valid){
    printf("Choose bracketing method. [1]:ZBRAC [2]:ZBRAK \n");
    scanf("%i",&method);
    if(method==1 || method==2) valid=1;
  }

  if(method==1){ //ZBRAC
    double x0, x1;
    printf("-------------- ZBRAC -----------\n");
    printf("Entrer first internal value: ");
    scanf("%lf",&x0);
    printf("Entrer second internal value: ");
    scanf("%lf",&x1);
    if(zbrac(func,&x0,&x1)){
      printf("\n ==> Updated range to [%lf,%lf]\n",x0,x1);
    }
    else printf("ZBRAC could not converge \n");
    
  }
  else if(method==2){ //ZBRAK
    int N;
    int nMaxRoot=NTRY; //if initialiase to 0, the 2 variable size arrays below will be same. 
    double rlow[nMaxRoot], rhigh[nMaxRoot];
    double x0, x1;
    
    printf("-------------- ZBRAK -----------\n");
    printf("Entrer first internal value: ");
    scanf("%lf",&x0);
    printf("Entrer second internal value: ");
    scanf("%lf",&x1);
    printf("Entrer the number of sub intervals: ");
    scanf("%i",&N);
    printf("Entrer the max number of roots to seek: ");
    scanf("%i",&nMaxRoot);
    
    zbrak(func,x0,x1,N, rlow, rhigh, &nMaxRoot);
    printf("\n ==> Number of roots found: %i\n",nMaxRoot);
    for(int i=0; i<nMaxRoot; i++){
      printf("Range %i: [%lf, %lf] \n",i,rlow[i], rhigh[i]);
    }
    
  }
  
  return 0;
}
//____________________________________________________
//____________________________________________________

//____________________________________________________
void swap(double* a, double* b){
  if(*a>*b){
    double temp = *a;
    *a = *b;
    *b = temp;
  }
}


//____________________________________________________
double F1(double x)
{
  return pow(x,3) + pow(x,2) + x - 7;   
}
//____________________________________________________
double F2(double x)
{
  return x*x - 4 * sin(x);            
}
//____________________________________________________
double F3(double x)
{
  return 2 * sin(x) - x*x - exp(-x);  
}
//____________________________________________________
double F4(double x)
{
  return  x*x;                        
}
//____________________________________________________
double F5(double x)
{
  return 1/(x-1);                     
}

//____________________________________________________
int zbrac(double (*f)(double), double *a, double *b)
{
  if(*a == *b){
    printf("ZBRAC: invalid initalization interval \n");
    exit(1);
  }

  double f1 = (*f)(*a);
  double f2 = (*f)(*b);
  for(int i=1; i<NTRY; i++){
    if(f1*f2<0){
      swap(a,b);
      return 1;
    }
    if(fabs(f1) < fabs(f2)){
      *a += FACTOR * (*a - *b); 
      f1 = (*f)(*a);
      if(dbg) printf("\t Update a=%lf\n",*a);
    }
    else{
      *b += FACTOR * (*b - *a); 
      f2 = (*f)(*b);
      if(dbg) printf("\t Update b=%lf\n",*b);
    }
    if(dbg){
      printf("Iteration %i a=%lf f1=%lf b=%lf f2=%lf\n",i,*a,f1,*b, f2); 
    }
  }
  
  return 0;
}

//____________________________________________________
void zbrak(double (*f)(double), double a, double b,
	   int n, double xlow[], double xhigh[], int *nrmax)
{
  double x;
  int nr =0;
  
  double dx = (b - a)/n; //determine the interval size
  double fp = (*f)(x=a); //compute function at a and initialize x

  if(dbg) printf("\t Interval size=%lf fp=%lf\n",dx, fp);
  
  for(int i=1; i<=n; i++){ //loop over interval
    double fc = (*f)(x += dx);  //compute f at next value x
    if(dbg) printf("\t x=%lf fc=%lf \n",x,fc);
    if(fc*fp<0){ //sign change - save bound values
      xlow[nr]   = x-dx;
      xhigh[nr]  = x;
      if(dbg) printf("\t New boundary found i=%i xlow=%lf, xhigh=%lf \n",nr,xlow[nr],xhigh[nr]);
      nr++;
      if(nr == *nrmax) return; //reach max number of root requested.
    }
    fp=fc;
  }
  *nrmax = nr;//to return the number of roots found
}
