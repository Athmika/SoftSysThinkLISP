void extractCommand(char* input, char* command, int* end)
{
    int i = 0;
    int start;
    while (input[i] != ')') {
      if (input[i] == '(')
      {
        start = i;
      }
      i++;
    }
    *end = i+1;

    strncpy(command, (input+start), i);

}

char* extractDigits(int* i_ptr, char* input,char* numBuffer)
{
    int start = *i_ptr;
    int numsize = 0;
    while(checkIfNum(input[*i_ptr]) == 1)
    {
      numsize++;
      *i_ptr = *i_ptr + 1;
    }
   strncpy(numBuffer, (input+start), numsize);

    return numBuffer;
}
