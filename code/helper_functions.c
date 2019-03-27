#include "helper_functions.h"

/*
extractCommand: helps extract (if (test_clause) (command1) (command2))  command1 and command2 from the if statement

PARAMETERS
input: char pointer
command: char pointer
end: int pointer

*/

void extractCommand(char* input, char* command, int* end)
{
    int i = 0;
    int start;
    while (input[i] != ')' && i<strlen(input)) {
      if (input[i] == '(')
      {
        start = i;
      }
        i++;
    }
    if (i>=strlen(input)) {printf("ERROR: Missing ')' ");}
    *end = i+1;

    strncpy(command, (input+start), i);

}

/*
extractCommand: helps extract the numbers in a LISP command

PARAMETERS
input: char pointer
i_ptr: int pointer
numBuffer: char pointer
*/

char* extractDigits(int* i_ptr, char* input,char* numBuffer)
{
    int start = *i_ptr;
    int numsize = 0;
    while(checkIfNum(input[*i_ptr]) == 1)
    {
      numsize++;
      *i_ptr = *i_ptr + 1;
    }
   strncpy(numBuffer, (input+start), numsize);

    return numBuffer;
}

/*
extractCommand: checks if a character is a number

PARAMETERS
num: char
*/

int checkIfNum(char num)
{
  char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
  int i = 0;
  for(i=0;i<10;i++)
  {
    if (num == nums[i])
    {
      return 1;
    }
  }
  return 0;
}
