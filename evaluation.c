/*
Implemnting an interactive prompt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define LESS '<'
#define GREATER '>'
#define EQUAL '='

float compute_ADD();
float compute_DIV();
float compute_MUL();
float compute_SUB();
bool cond_LESS();
bool cond_GREATER();
bool cond_EQUAL();

int isspace();

typedef enum{
  FLOAT, BOOLEAN
} types;

typedef union result{
  float number;
  bool conditional;
}result;

typedef struct{
  result results;
  types units;
} temps;



void evaluate(char* input,temps* temp){
  //function does numerical evaluation
  if (*(input++) != '('){ //check value of input, check for open paren, increment by 1
    printf("ERROR: Input must begin with a '('\n");
    printf("ERRORRRRRRR");
    //return 0;
  }

  *input = *(input++);
  char operator = *input; //read the operator
  //bool resultBool;
  switch (operator) {
    case ADD:
      temp->results.number = compute_ADD(input);
      temp->units = FLOAT;
      break;
    case MUL:
      temp->results.number = compute_MUL(input);
      temp->units = FLOAT;
      break;
    case DIV:
      temp->results.number = compute_DIV(input);
      temp->units = FLOAT;
      break;
    case SUB:
      temp->results.number = compute_SUB(input);
      temp->units = FLOAT;
      break;
    case LESS:
      temp->units = BOOLEAN;
      temp->results.conditional = cond_LESS(input);
      break;
    case GREATER:
      temp->units = BOOLEAN;
      temp->results.conditional = cond_GREATER(input);
      break;
    case EQUAL:
      temp->units = BOOLEAN;
      temp->results.conditional = cond_EQUAL(input);
      break;
    default:
      printf("ERROR--NO OPERATOR PROVIDED");
      break;
  }
}

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
  bool result = true;
  int num1 = input[1]-'0';
  int num2 = input[3]-'0';
  if((num1 < num2)){
   result = true;
  }
  else{
   result = false;
  }
  // printf(result ? "true" : "false");

  return result;
}


bool cond_GREATER(char* input)
{
  bool result;

  int num1 = input[1]-'0';
  int num2 = input[3]-'0';
  if((num1 > num2)){
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
  //printf("%s\n", input);
  int num1 = input[1]-'0';
  int num2 = input[3]-'0';
  if((num1 == num2)){
   result = true;
  }
  else{
   result = false;
  }
  return result;
}

float compute_ADD(char* input){
  float sum = 0;
  int i = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      int start = i;
      int numsize = 0;
      while(checkIfNum(input[i])==1)
      {
        numsize++;
        i++;
      }
      char* numBuffer = malloc(15*sizeof(char));
      strncpy(numBuffer, (input+start), numsize);
      float curr = atof(numBuffer);
      sum = sum + curr;
      free(numBuffer);
  }
  }
    return sum;
  }

  float compute_SUB(char* input){
    float difference = 0;
    int i = 0;
    int first = 0;
    while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      int start = i;
      int numsize = 0;
      while(checkIfNum(input[i])==1){
        numsize++;
        i++;
      }
      char* numBuffer = malloc(15*sizeof(char));
      strncpy(numBuffer, (input+start), numsize);
      float curr = atof(numBuffer);
      if (first != 0)
        curr = (-1.0)*curr;
      first = 1;
      difference = difference + curr;
      free(numBuffer);
  }
  }
  return difference;
}

  float compute_MUL(char* input) {
    float product = 1;
    int i = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      int start = i;
      int numsize = 0;
      while(checkIfNum(input[i])==1)
      {
        numsize++;
        i++;
      }
      char* numBuffer = malloc(15*sizeof(char));
      strncpy(numBuffer, (input+start), numsize);
      float curr = atof(numBuffer);
      product = product * curr;
      free(numBuffer);
  }
  }
  return product;
}

  float compute_DIV(char* input) {
    float quotient = 1.0;
    int i = 0;
    int first = 0;

    while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      int start = i;
      int numsize = 0;
      while(checkIfNum(input[i])==1)
      {
        numsize++;
        i++;
      }
      char* numBuffer = malloc(15*sizeof(char));
      strncpy(numBuffer, (input+start), numsize);
      float curr = atof(numBuffer);
      if (first != 0)
        curr = 1.0 / curr;
      first = 1;
      quotient = quotient * curr;
      free(numBuffer);
    }
    }
    return quotient;
    }


int cond(char* input)
{

  char* firstsubstr = malloc(3*sizeof(char));
  strncpy(firstsubstr, (input+1), 2);

  char* secondsubstr = malloc(15*sizeof(char));

  strncpy(secondsubstr, (input+3), strlen(input)-3);

  //printf("%s\n", substr);
  //char firstChar = input[0];
  if (strcmp(firstsubstr,"if") == 0) {
    int i = 0;
    //skip forward until you hit the first comparator operator
    while (isspace(secondsubstr[0]) || secondsubstr[0] == '(')
    {
      secondsubstr = secondsubstr + 1;
      i =+ 1;
      //nextChar = secondsubstr[i];
    }

    char cmpOperator = secondsubstr[0];

    //need to error check to make sure these are actually ints
    int num1 = secondsubstr[2]-'0';
    int num2 = secondsubstr[4]-'0';

    if (cmpOperator == '<')
    {
        if (num1 < num2) {printf("true\n");}
    }
    else if (cmpOperator == '>')
    {
        if (num1 > num2) {printf("true\n");}
    }
    else if (cmpOperator == '=')
    {
        if (num1 == num2) {printf("true\n");}
    }
    else{
        printf("Invalid comparision operator");
     }

  }

return 0;
}

int main(int argc, char** argv) {

  /* Print Version and Exit Information */
 char *inputs[101];

  printf("lisp> ");
  char s[201];
  char input[201];
  int numInputs = 0;
  int i = 0;

//This loop goes through all the lines of input until a blank line is entered

  while (1 == scanf("%[^\n]%*c", s))
  {
    printf("lisp> ");
    //Error checking to make sure that command size is not greater than 200
    if (strlen(s)>201)
    {
      printf("Your command cannot be more than 200 characters\n");
      exit(1);
    }
    inputs[i] = malloc(100 * sizeof(char));

    char *str_ptr = s;
    int x = 0;

    //The loop removes the leading spaces
    for (x=0;x<strlen(s);x++)
    {
      if(isspace(s[x]))
      {
        str_ptr = str_ptr + 1;
      }
      else
      {
        break;
      }
    }

    strcpy(inputs[i],str_ptr);

    numInputs++;
    i++;

    //Error checking to make sure that the number of commands is not greater than 100
    if (numInputs > 100)
    {
        printf("You cannot enter more than 100 commands\n");
        exit(1);
    }
  }

  i = 0;
  //Loop prints out all the inputs

  result *res = malloc(sizeof(float));
  temps *temp = malloc(sizeof(float) * 10 );

  while(numInputs>0)
  {
    evaluate(inputs[i], temp);
    if (temp->units == BOOLEAN){
      if(temp->results.conditional = 1)
          printf("True\n");
      else
          printf("False\n" );
    }
    else if(temp->units == FLOAT){
      printf("float");
      printf("%f\n",temp->results.number);
      printf("%d\n",temp->results.conditional);

    }
      //printf("%s\n", inputs[i]);
       i++;
       numInputs--;
  }


  return 0;
}
