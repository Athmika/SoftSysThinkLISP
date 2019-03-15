#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//http://leohetsch.com/create-a-minimal-lisp-like-interpreter-in-c/

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

float compute_ADD();
float compute_DIV();
float compute_MUL();
float compute_SUB();

int isspace();



char* read_input(){
//function reads user input and returns pointer to the input string
  char* input=malloc(25600);
  printf("lispy-> ");
  fgets(input, 25600, stdin);
  return input;
}

float evaluate(char* input){
  //function does numerical evaluation
  if (*(input++) != '('){ //check value of input, check for open paren, increment by 1
    printf("ERROR: Input must begin with a '('\n");
    printf("ERRORRRRRRR");
    return 0;
  }else{
    input++;
  }

  *input = *(input++);
  char operator = *input; //read the operator
  float result = 0;
  switch (operator) {
    case ADD:
      result = compute_ADD(input);
      return result;
      break;
    case MUL:
      result = compute_MUL(input);
      return result;
      break;
    case DIV:
      result = compute_DIV(input);
      return result;
      break;
    case  SUB:
      result = compute_SUB(input);
      return result;
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


int main(int argc, char* argv[]) {
  while (1) {
    printf("-> %f\n", evaluate(read_input()));
}

    return 0;
}
