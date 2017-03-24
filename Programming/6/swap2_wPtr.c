#include <stdio.h>

/*
  Description: Swap variable using function
  Author: Anyes Taffard
*/

//Swap the content of a & b
void swap(int* a, int* b);

//____________________________________________
//____________________________________________
int main()
{
  int i,j;

  printf("Enter two numbers: \n");
  scanf("%d %d",&i, &j);

  printf("Before swap i = %i \t j = %i \n",i, j);
  swap(&i,&j);
  printf("After swap i = %i \t j = %i \n",i, j);
  
  return 0;
}

//____________________________________________
void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
