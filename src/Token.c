#include "token.h"
#include <stdio.h>

void create_new_token(const char* buffer, TokenType type){
  printf("Created Token\n\tContent: %s\n\t%d\n", buffer, type);
}
