
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buffer[2048];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}


int main(int argc, char** argv) {
  char* input = readline("lispy> ");
  printf("%s" ,input[1]);
  return 0;
}
