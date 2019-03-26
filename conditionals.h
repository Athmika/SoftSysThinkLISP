#include "helper_functions.h"

#define LESS '<'
#define GREATER '>'
#define EQUAL '='

bool cond_LESS();
bool cond_GREATER();
bool cond_EQUAL();
int checkIfNum(char);
void if_cond();


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
