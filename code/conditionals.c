#include "conditionals.h"

/*
cond_LESS: when a command of the form (< num1 num2) is input, this function returns a boolean result

PARAMETERS
input: char pointer
*/

bool cond_LESS(char* input)
{
  bool result;
  int i = 0;
  int* i_ptr = &i;
  int nums[2];
  int x = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      nums[x] = curr;
      x++;
      free(numBuffer);
  }
  }

  if((nums[0] < nums[1])){
   result = true;
  }
  else{
   result = false;
  }
  return result;
}

/*
cond_GREATER:  when a command of the form (> num1 num2) is input, this function returns a boolean result

PARAMETERS
input: char pointer
*/

bool cond_GREATER(char* input)
{
  bool result;
  int i = 0;
  int* i_ptr = &i;
  int nums[2];
  int x = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      nums[x] = curr;
      x++;
      free(numBuffer);
  }
}

  if((nums[0] > nums[1])){
   result = true;
  }
  else{
   result = false;
  }
  return result;
}

/*
cond_EQUAL: when a command of the form (= num1 num2) is input, this function returns a boolean result

PARAMETERS
input: char pointer
*/

bool cond_EQUAL(char* input)
{
  bool result;
  int i = 0;
  int* i_ptr = &i;
  int nums[2];
  int x = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      nums[x] = curr;
      x++;
      free(numBuffer);
      }
    }

  if((nums[0] == nums[1])){
   result = true;
  }
  else{
   result = false;
  }
  return result;
}

/*
if_cond: when a command of the form (if (test_clause) (command1) (command2)) is input, this function calls evaluate on command1 if the test_clause is true or
command2 if the test_clause is false.

PARAMETERS
input: char pointer
data: pointer to a struct of type outputWithUnits

*/


void if_cond(char* input, outputWithUnits* data)
{

  char* firstsubstr = malloc(4*sizeof(char));
  strncpy(firstsubstr, (input), 2);
  char* secondsubstr = malloc(15*sizeof(char));
  strncpy(secondsubstr, (input+2), strlen(input)-2);

  float nums[2];
  int index = 0;
  if (strcmp(firstsubstr,"if") == 0) {

    char cmpOperator = secondsubstr[2];
    int i = 0;
    int* i_ptr = &i;

    while (secondsubstr[i] != ')') {
    if (isspace(secondsubstr[i]) || checkIfNum(secondsubstr[i]) == 0)
    {
      i++;
    }
    else{
    char* numBuffer = malloc(15*sizeof(char));
    numBuffer = extractDigits(i_ptr,secondsubstr,numBuffer);
    nums[index] = atof(numBuffer);

    if (index>2)
    {
      printf("ERROR: IF CONDITION CAN ONLY COMPARE 2 NUMBERS\n");
      exit(1);
    }

    index++;
   }
   }

    int* end = malloc(5);
    char* command1 = malloc(15*sizeof(secondsubstr));
    extractCommand(secondsubstr+i+1,command1,end);


    char* command2 = malloc(15*sizeof(secondsubstr));
    extractCommand(secondsubstr+i+(*end+1),command2,end);


    if (cmpOperator == '<')
    {
        if (nums[0] < nums[1]) {evaluate(command1,data);} else {evaluate(command2,data);}
    }
    else if (cmpOperator == '>')
    {
        if (nums[0] > nums[1]) {evaluate(command1,data);} else {evaluate(command2,data);}
    }
    else if (cmpOperator == '=')
    {
        if (nums[0] == nums[1]) {evaluate(command1,data);} else {evaluate(command2,data);}
    }
    else{
        printf("ERROR: Invalid comparision operator\n");
        exit(1);
     }
  }

  else{
      printf("ERROR: COMMAND NOT RECOGNIZED. OPERATOR (+,-,/,*,<,>,=) OR CONDITIONAL(if) NOT provided");
      exit(1);
    }
}
