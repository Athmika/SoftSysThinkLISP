/*
Implemnting an interactive prompt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  while(numInputs>0)
  {

    cond(inputs[i]);
      //printf("%s\n", inputs[i]);
       i++;
       numInputs--;
  }


  return 0;
}
