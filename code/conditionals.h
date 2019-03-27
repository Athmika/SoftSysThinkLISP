#include "helper_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef enum{
  FLOAT, BOOLEAN
} types;

typedef union result{
  float number;
  bool conditional;
}result;

typedef struct{
  result results;
  types units;
} temps;


#define LESS '<'
#define GREATER '>'
#define EQUAL '='

bool cond_LESS();
bool cond_GREATER();
bool cond_EQUAL();
int checkIfNum(char);
void if_cond();
void evaluate();
