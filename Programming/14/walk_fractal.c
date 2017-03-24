#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


/*
  Description: Random walk with diffusion limited aggregation

  random walk particle and stop at the position when collide
  
  Author A. Taffard
*/

const int debug =0;

const int nParticles = 1000; //Number of particle launch
const int nSteps     = 1000; //max number of random steps before stopping
const int initialRadius = 50;

/*
  Use Marsaglia's RNG 
*/
unsigned long long int v;
//_______________________________________________
unsigned long long int64() {
  v ^= v >> 21; v ^= v << 35; v ^= v >> 4;
  return v*2685821657736338717LL;
}
//_______________________________________________
void setSeed(unsigned long long int j) {
  v = 4101842887655102017LL;
  v ^= j;
  v = int64();
}
//_______________________________________________
double myRandom() {
  return 5.42101086242752217e-20*int64();
}

//_______________________________________________
double randomAngle()
{
  return myRandom()*2*M_PI;
}

//_______________________________________________
//Take a random step inside the current radius
void randomStep(double pos[2]){
  double theta = randomAngle();
  pos[0] += cos(theta);
  pos[1] += sin(theta);
}

//__________________________________________________
int hasCollided(double pos[2],double existingArray[],int nExist) 
{
  for(int i=0; i<nExist; i++){
    double dx = existingArray[2*i]-pos[0];
    double dy = existingArray[2*i+1]-pos[1];
    double dRSquare = dx*dx + dy*dy;
    if(dRSquare <= 1.){
      if(debug) printf("\t\tCollided dR %lf",dRSquare);
      return 1; //particle collided
    }
  }

  return 0;
}

//__________________________________________________
void writeData(char fileName[], int aSize, double array[])
{
  FILE* fPtr;
  fPtr = fopen(fileName,"w"); 
  if( fPtr == NULL ){
    printf("Cannot open file %s. Exitting\n",fileName);
    exit(1);
  }
  printf("Opened file %s \n",fileName);
  
  for(int i=0; i<aSize; i++){
    fprintf(fPtr,"%lf %lf \n",array[2*i],array[2*i+1]);
  }
  
  fclose(fPtr);
}

//__________________________________________________
//__________________________________________________
int main(){
  //Postion of each particles after the random walk
  // X: ith position
  // Y i+1 position
  double fractal[2*nParticles];
  memset(fractal,0,sizeof(fractal[0])*2*nParticles);  
  
  //Set Random seed
  setSeed( time(NULL) * 391740128);

  //Radius of the cluster
  double radius = initialRadius;

  //Loop over the particle to launch
  int iParticle = 1;
  while (iParticle < nParticles){
    double angle = randomAngle();
    double pos[2]; //initial x,y coordinate
    pos[0] = radius * cos(angle);
    pos[1] = radius * sin(angle);

    if(debug) printf("Launch particle %i Initial X %lf Y %lf\n",
		     iParticle, pos[0], pos[1]);
    
    //Do the random steps up to nSteps or collision
    // If the particle fails to collide w/ an existing one after
    // nSteps, a new one is launch
    int iStep=0;
    while(iStep < nSteps){
      randomStep(pos);
      //Check if collided with an existing particle
      // 1st particle is made to "vitually collide" at 0,0 
      if( hasCollided(pos,fractal,iParticle) ){
	if(debug) printf("\t Particle %i collided after %i steps X: %f Y: %f\n",
			 iParticle, iStep, pos[0], pos[1]);
	
	//Save position of this particle
	fractal[2*iParticle]=pos[0];
	fractal[2*iParticle+1]=pos[1];
	
	iParticle++; //go to the next particle to launch	
	break; //this particle stops here
      }
      iStep++;
    }//iSteps
  }//iParticles

  //Dump output to file
  writeData("walkFractal.dat",nParticles, fractal);

  return 0;

}
