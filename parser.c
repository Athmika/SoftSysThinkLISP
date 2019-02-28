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
  if (*(input++) != '('){ //check value of input, check for open paren, increment by 1
    printf("ERROR: Input must begin with a '('\n");
  }
  char* operator = *(input++); //read the operator

  int result = 0;
  switch (operator) {
    case ADD:
      result = compute_ADD(input);
      break;
    default: break;
  }
}

int compute_ADD(char* input){
  int sum = 0;

  while (*input != ')') {
    if (*input == ' '){
      input++;
      continue;
    }
    int a = 0;
    scanf(input++, "%d",&a);
    sum += a;
  }
  return sum;
}

int main(int argc, char*argv[]){
  while (1){
    evalute(read_input());
  }

  return 0;
}


int main(int argc, char* argv[]) {

    return 0;
}
