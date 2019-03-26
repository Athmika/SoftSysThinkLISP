#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'


loat compute_ADD(char* input){
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
