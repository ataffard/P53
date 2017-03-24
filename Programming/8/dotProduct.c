#include <stdio.h>

/*
  Description: Perform the dot and cross product between two 3D vectors

  Author: Anyes Taffard
*/


/*
Returns the generalized n-dimensional dot product of input vectors u,v
*/
double dotProduct(double u[],double v[],int n) {
    int k;
    double result = 0;
    for(k = 0;k < n;k++) {
        result += u[k]*v[k];
    }
    return result;
}

/*
Calculates a 3-dimensional cross product of input vectors u,v and stores
the result in the uv array provided. Note that this function does not
create the uv array: this is the responsibility of the caller.
*/
void crossProduct(double u[],double v[],double uv[]) {
    int i,j,k;
    for(i = 0; i < 3; i++) {
        j = (i+1)%3;
        k = (i+2)%3;
        uv[i] = u[j]*v[k] - u[k]*v[j];
    }
    return;
}

int main() {
    /* Declare the variables we will use */
    double u[3],v[3]; /* 3D vectors */
    
    /* Ask the user to initialize the vectors */
    printf("Enter the first vector (x,y,z,): ");
    scanf("%lf %lf %lf",&u[0],&u[1],&u[2]);
    printf("Enter the second vector (x,y,z) : ");
    scanf("%lf %lf %lf",&v[0],&v[1],&v[2]);

    /* Test the functions declared above */
    double dot = dotProduct(u,v,3);
    printf("The dot product is %f\n",dot);

    double cross[3];
    crossProduct(u,v,cross);
    printf("The cross product (x,y,z) is (%f,%f,%f)\n",
	   cross[0],cross[1],cross[2]);

    return 0;
}
