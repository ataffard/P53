/*
  Description: Example of passing function as argmument 

  Author: Anyes Taffard
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int RANGE = 10;

//___________________________________
void evaluate(double (*f)(double))
{
  for(int i=-RANGE; i<RANGE; i++){
    double x=i*0.1;
    printf("f(%2.3f)=%2.3f \n",x,f(x));
  }
}
//___________________________________
double F1(double x){
  return 2*pow(x,3);
}
//___________________________________
double F2(double x){
  return 1/(x-1);
}
//___________________________________
//___________________________________
int main()
{
  double (*func)(double);

  printf("Evaluate F1\n");
  func = *F1;
  evaluate(func);

  printf("\nEvaluate F2\n");
  func = *F2;
  evaluate(func);
  
  return 0;
}
