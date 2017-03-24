#include <stdio.h>
#include <math.h>

/* 
   Description: Compute the quadratic of a*x^2 + b*x + c = 0

   Author: Anyes Taffard
*/

int main() {
  /* Declare the variables we will use */
  double a,b,c,disc;
  
  /* Get the quadratic coefficients from the user */
  printf("Enter coefficients a,b,c of a x^2 + b x + c = 0: \n");
  scanf("%lf %lf %lf",&a, &b,&c);
  
  /* Calculate the discriminant b^2 - 4 a c */
  disc = b*b - 4*a*c;
    
  /* What type of solution do we have for x? */
  if(disc > 0) {
    printf("Solutions are x = %f and x = %f\n",
	   (-b-sqrt(disc))/(2*a),(-b+sqrt(disc))/(2*a));
  }
  else if(disc == 0) {
    printf("Solution is x = %f\n",-b/(2*a));
  }
  else {
    printf("No real solutions\n");
  }
  
  return 0;
}

