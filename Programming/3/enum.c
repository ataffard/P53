/*
  Description: Enum example
  Author: Anyes Taffard
*/
#include <stdio.h>

enum DAY{        /* Define an enumeration type     */
  staturday,     /* Names a day and declares a     */
  sunday = 0,    /* variables name workday with    */
  monday,        /* that type                      */
  tuesday,
  wednesday,     /* wednesday is associated with 3 */ 
  thursday,
  friday
}; 

enum BOOL{       /* Define a BOOL type             */
  false,         /* false = 0                      */
  true           /* true  = 1                      */
};


int main()
{
  enum DAY today = wednesday;
  enum DAY tomorrow = today + 1;

  enum BOOL isToday = false;

  enum DAY aDay = wednesday;

  printf("Today is %i\n", today);
  printf("Tomorrow is %i\n", tomorrow);
  
  if(aDay == today) isToday = true;
  else if (aDay == tomorrow) isToday = false;

  printf("a day is %i. Is it today ? %i \n",aDay, isToday);

  return 0;
}
