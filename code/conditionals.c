#include "conditionals.h"

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

void if_cond(char* input, temps* temp)
{

  char* firstsubstr = malloc(4*sizeof(char));
  strncpy(firstsubstr, (input), 2);
  char* secondsubstr = malloc(15*sizeof(char));
  strncpy(secondsubstr, (input+2), strlen(input)-2);

  float nums[2];
  //char firstChar = input[0];
  int index = 0;
  if (strcmp(firstsubstr,"if") == 0) {

    char cmpOperator = secondsubstr[2];
    int i = 0;
    int* i_ptr = &i;
    //skip forward until you hit the first comparator operator

    while (secondsubstr[i] != ')') {
    if (isspace(secondsubstr[i]) || checkIfNum(secondsubstr[i]) == 0)
    {
      i++;
      //nextChar = secondsubstr[i];
    }
    else{
    //need to error check to make sure these are actually ints
    char* numBuffer = malloc(15*sizeof(char));
    numBuffer = extractDigits(i_ptr,secondsubstr,numBuffer);
    nums[index] = atof(numBuffer);

    if (index>2)
    {
      printf("ERROR: IF CONDITION CAN ONLY COMPARE 2 NUMBERS\n");
    }

    index++;
   }
   }

    int* end = malloc(5);
    char* command1 = malloc(15*sizeof(secondsubstr));
    extractCommand(secondsubstr+i+1,command1,end);


    char* command2 = malloc(15*sizeof(secondsubstr));
    extractCommand(secondsubstr+i+(*end+1),command2,end);
    //printf("%s\n",command2);



    if (cmpOperator == '<')
    {
        if (nums[0] < nums[1]) {evaluate(command1,temp);} else {evaluate(command2,temp);}
    }
    else if (cmpOperator == '>')
    {
        if (nums[0] > nums[1]) {evaluate(command1,temp);} else {evaluate(command2,temp);}
    }
    else if (cmpOperator == '=')
    {
        if (nums[0] == nums[1]) {evaluate(command1,temp);} else {evaluate(command2,temp);}
    }
    else{
        printf("ERROR: Invalid comparision operator\n");
     }

  }
else{
  printf("ERROR: COMMAND NOT RECOGNIZED. OPERATOR (+,-,/,*,<,>,=) OR CONDITIONAL(if) NOT provided");
}
}
