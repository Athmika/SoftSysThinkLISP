#include "simple_operations.h"

/*
computeADD: when a command of the form (+ num1 num2 num3...) is input, this function returns the sum of all the numbers enetered

PARAMETERS
input: char pointer
*/

float compute_ADD(char* input){
  float sum = 0;
  int i = 0;
  int* i_ptr = &i;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      sum = sum + curr;
      free(numBuffer);
  }
  }
    return sum;
  }

  /*
  compute_SUB: when a command of the form (- num1 num2 num3...) is input, this function returns num1 - num2 - num3 - ...

  PARAMETERS
  input: char pointer
  */

float compute_SUB(char* input){
    float difference = 0;
    int i = 0;
    int* i_ptr = &i;
    int first = 0;
    while (input[*i_ptr] != ')') {
    if (isspace(input[*i_ptr]) || checkIfNum(input[*i_ptr])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
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

/*
compute_MUL: when a command of the form (* num1 num2 num3...) is input, this function returns the product of all the numbers entered

PARAMETERS
input: char pointer
*/

float compute_MUL(char* input) {
    float product = 1;
    int i = 0;
    int* i_ptr = &i;
   while (input[i] != ')') {
     if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      product = product * curr;
      free(numBuffer);
  }
  }
  return product;
}

/*
compute_DIV: when a command of the form (/ num1 num2 num3...) is input, this function returns ((num1 / num2)/num3)...) 

PARAMETERS
input: char pointer
*/

float compute_DIV(char* input) {
    float quotient = 1.0;
     int i = 0;
    int* i_ptr = &i;
    int first = 0;
    while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
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
