#include <stdio.h>
#include <stdlib.h>

//http://leohetsch.com/create-a-minimal-lisp-like-interpreter-in-c/

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

char* read_input(){
//function reads user input and returns pointer to the input string
  char* input=malloc(25600);
  fgets(input, 25600, stdin);
  printf("%s\n",input);
  return input;
}

int evaluate(char* input){
  printf("Hello Hyegi1");
  //function does numerical evaluation
  if (*(input++) != '('){ //check value of input, check for open paren, increment by 1
    printf("ERROR: Input must begin with a '('\n");
    exit(1);
  }

  printf("Hello Hyegi2");
  *input = *(input++)
  char* operator = *input; //read the operator
  int result = 0;
  switch (operator) {
    case ADD:
      result = compute_ADD(input);
      break;
    case MUL:
      result = compute_MUL(input);
      break;
    case DIV:
      result = compute_DIV(input);
      break;
    case  SUB:
      result = compute_SUB(input);
      break;
    default:
      printf("ERROR--NO OPERATOR PROVIDED");
      break;
  }
}

int compute_ADD(char* input){
  int sum = 0;

  while (*input != ')') {
    if (*input == ' '){
      input++;
      continue;
    }
    int a = atoi(input);
    printf("hello")
    // scanf(input++, "%d",&a);
    sum += a;
  }
  return sum;
}

int compute_MUL(char* input) {

    int product = 1; // 1 is neutral for product

    while (*input != ')') {
        if (*input == ' ') {
            input++; continue;
        }

        int m = 0;
        sscanf(input++, "%d", &m);
        product *= m;
    }

    return product;
}

int compute_DIV(char* input) {
    int  t= 0;
    int n = 0;

    while(*(++input) == ' ');

    // first value found
    sscanf(read_input, "%d", &t);
    ++input;

    while(*(++input) == ' ');

    // second value found
    sscanf(input, "%d", &n);

    return t / n;
}

int compute_SUB(char* input){
  int  f= 0;
  int l = 0;

  while(*(++input) == ' ');

  // first value
  sscanf(read_input, "%d", &f);
  ++input;

  while(*(++input) == ' ');

  // second value
  sscanf(input, "%d", &l);
  return f-l;
}

int main(int argc, char* argv[]) {
  while (1) {
    printf("-> %d", evaluate(read_input()));
}

    return 0;
}
