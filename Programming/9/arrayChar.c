#include <stdio.h>
#include <string.h>

/*
  Description: Array of char

  Author: Anyes Taffard
*/

int main() {

  char word1[]="Hello World!";
  printf("%s \n\n",&word1[0]);

  char word2[6];
  word2[0]='H';
  word2[1]='e';
  word2[2]='l';
  word2[3]='l';
  word2[4]='o';
  word2[5]='\0'; //C null character. Signal string termination
  //word2[0] = 'WORD'; //Illegal !
  printf("%s \n\n",word2);
  
  char *word3 = "four";
  printf("%s \n\n",word3);
  

  char* string1 ="Hello";
  char* string2 ="World";

  char string3[12];
  strcpy(string3,string1);
  printf("%s \n\n",string3);
  strcat(string3," ");
  strcat(string3,string2);
  printf("%s \n\n",string3);
  
  return 0;
}
