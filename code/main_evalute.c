#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "simple_operations.h"
#include "conditionals.h"

/*

evaluate: return the output of a LISP command. Four arthimetic operators, three comparitive operators, and the if statement is implemented.

PARAMETERS
input: char pointer
data: pointer to a struct of type outputWithUnits

*/

void evaluate(char* input, outputWithUnits* data){

  //if an open param is not detected as the first character return an error
  if (*(input++) != '('){
    printf("ERROR: Input must begin with a '('\n");
    exit(1);
  }

  char operator = input[0];

  switch (operator) {
    case ADD:
      data->results.number = compute_ADD(input);
      data->units = FLOAT;
      break;
    case MUL:
      data->results.number = compute_MUL(input);
      data->units = FLOAT;
      break;
    case DIV:
      data->results.number = compute_DIV(input);
      data->units = FLOAT;
      break;
    case SUB:
      data->results.number = compute_SUB(input);
      data->units = FLOAT;
      break;
    case LESS:
      data->units = BOOLEAN;
      data->results.conditional = cond_LESS(input);
      break;
    case GREATER:
      data->units = BOOLEAN;
      data->results.conditional = cond_GREATER(input);
      break;
    case EQUAL:
      data->units = BOOLEAN;
      data->results.conditional = cond_EQUAL(input);
      break;
    default:
      if_cond(input,data);
      break;
  }
}



int main(int argc, char** argv) {

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

    //The loop removes the leading spaces in the input string
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

  result *res = malloc(sizeof(float));
  outputWithUnits *data = malloc(sizeof(float) * 10 );

  while(numInputs>0)
  {

    evaluate(inputs[i], data);

    if (data->units == BOOLEAN){
      if(data->results.conditional == 1)
          printf("True\n");
      else
          printf("False\n" );
    }
    else if(data->units == FLOAT){
      printf("%f\n",data->results.number);

    }
       i++;
       numInputs--;
  }

return 0;
}
