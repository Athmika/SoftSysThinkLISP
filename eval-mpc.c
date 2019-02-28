/*
Implemnting an interactive prompt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {

  /* Print Version and Exit Information */
 char *inputs[10];

  printf("lisp> ");
  char s[100];
  char input[100];
  int numInputs = 0;
  int i = 0;

  while (1 == scanf("%[^\n]%*c", s))
  {
    printf("lisp> ");
    //Error checking to make sure that input size is not greater than 100
    inputs[i] = malloc(100 * sizeof(char));
    strcpy(inputs[i],s);

    numInputs++;
    i++;
  }

  i = 0;
  while(numInputs>0)
  {
      printf("%s\n", inputs[i]);
       i++;
       numInputs--;
  }

  printf("Number of inputs = %i\n", numInputs);


  return 0;
}
