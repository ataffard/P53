#include <stdio.h>
#include <math.h>

/*
  Description: Loop example with break and continue

  Author: Anyes Taffard
*/

int main(){
  int i,j, k=0;

  printf("i\t j\t k\n");

  for(i=0; i<8; i++){
    for(j=0; j<8; j++){
      if(j==4) break;
      k++;
    }
    printf("%d\t %d\t %d\n",i,j,k);
  }

  printf("\n\n");

  printf("i\t j\t k\n");
  for(k=i=0; i<8; i++){
    for(j=0; j<8; j++){
      if(j==4) continue;
      k++;
    }
    printf("%d\t %d\t %d\n",i,j,k);
  }

  return 0;
}

