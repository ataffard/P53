#include <stdio.h>
#include <math.h>

/* This is a comment. The C compiler ignores it but the grader doesn't. */

/* A comment can be
split over
several lines */

//the rest of the line is commented

/*
  Description: Compute the 3rd side of a triangle give the size of the other two 
               and the angle between them.

  Author: Anyes Taffard
*/

int main() {   
  /* Declare and initialize the variables that we will use */
  double side1   = 5.0;     // the length of side 1 in arbitrary units 
  double side2   = 3.0;     // the length of side 2 in (the same) arbitrary units 
  double theta12 = 0.5;     // the angle between sides 1 and 2 in radians 
  
  double side3   = -1;     /* the length of the side 3 that we'll compute
			      not necessary to initialized, but adviced to do so to avoid surprises */
  
  /* Use the law of cosines to find the length of side 3 */
  side3 = sqrt( side1*side1 + side2*side2 - 2*side1*side2*cos(theta12) );
  
  /* print the result */
  printf("The length of side 3 is %f\n",side3);


  return 0;
}

