#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void evalute();

void evaluate(char* input,temps* temp){
  //function does numerical evaluation
  if (*(input++) != '('){ //check value of input, check for open paren, increment by 1
    printf("ERROR: Input must begin with a '('\n");
    exit(1);
    //return 0;
  }
  //*input = *(input++);
  char operator = input[0]; //read the operator
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
      if_cond(input,temp);
      break;
  }
}



nt main(int argc, char** argv) {

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
      printf("%f\n",temp->results.number);

    }
      //printf("%s\n", inputs[i]);
       i++;
       numInputs--;
  }


  return 0;
}
