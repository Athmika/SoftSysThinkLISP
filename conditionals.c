bool cond_LESS(char* input)
{
  bool result;
  int i = 0;
  int* i_ptr = &i;
  int nums[2];
  int x = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      nums[x] = curr;
      x++;
      free(numBuffer);
  }
  }

  if((nums[0] < nums[1])){
   result = true;
  }
  else{
   result = false;
  }
  return result;
}

bool cond_GREATER(char* input)
{
  bool result;
  int i = 0;
  int* i_ptr = &i;
  int nums[2];
  int x = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      nums[x] = curr;
      x++;
      free(numBuffer);
  }
}

  if((nums[0] > nums[1])){
   result = true;
  }
  else{
   result = false;
  }
  return result;
}

bool cond_EQUAL(char* input)
{
  bool result;
  int i = 0;
  int* i_ptr = &i;
  int nums[2];
  int x = 0;

  while (input[i] != ')') {
    if (isspace(input[i]) || checkIfNum(input[i])==0)  {
      i++;
    }
    else{
      char* numBuffer = malloc(15*sizeof(char));
      numBuffer = extractDigits(i_ptr,input,numBuffer);
      float curr = atof(numBuffer);
      nums[x] = curr;
      x++;
      free(numBuffer);
  }
}

  if((nums[0] == nums[1])){
   result = true;
  }
  else{
   result = false;
  }
  return result;
}
