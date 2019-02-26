#include <stdio.h>
#include <stdlib.h>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

char* read_input(){
//function reads user input and returns pointer to the input string
  char* input=malloc(256);
  fgets(input, 256, stdin);
  return input;
}

int evaluate(char* input){
  //function does numerical evaluation
  if (*(input) != '('){
    input = input + 2; //after checking input, increment by 1
    printf("ERROR: Input must begin with a '('\n");
    return 0;
  }
  //char* operator = *[input]
  return 0;
}



int main(int argc, char*argv[]){
  while (1){
    evalute(read_input());
  }

  return 0;
}
