#include <stdio.h>
#include <assert.h>
#include <math.h>

/* 
   Marsaglia Xorshift generator with period ~ 10^19"
   Range [0,1) of double
   Period of about 2 x 10^19. 
   Ok up to 10^12 calls  
   
   ^ (caret) is the bitwise XOR
   <<: bit shift operator
   LL: is for long long: 
   http://gcc.gnu.org/onlinedocs/gcc/Long-Long.html

   http://www.jstatsoft.org/v08/i14/paper
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
//_______________________________________________
int main() {
  int N = 100000;
  
  setSeed(24071966);

  for(int k = 0; k<N ; k++) {
    double randX = (double) myRandom();
    double randY = (double) myRandom();
    printf("%lf %lf\n",randX, randY);
  }
  return 0;
}
