#include <stdio.h>
#include <math.h>

/*
  Description: Loop example with break and continue

  Author: Anyes Taffard
*/

int main() {

  for(int index = 0; index < 1000; ++index) {
    int input;
    printf("What do you want to do? [0=normal,1=continue,2=break] ");
    scanf("%d",&input);
    printf("got input %d\n",input);
    
    if(input == 1) {
      continue;
    }
    if(input == 2) {
      break;
    }
    printf("index = %d\n",index);
  }
  printf("bye.\n");

  return 0;
}
