#include "token.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isInteger(const char* buffer) {
  int i = 0;
  while (buffer[i] != '\0') {
    if (buffer[i] < '0' || buffer[i] > '9') {
     return false;
    }
    i++;
  }
  return true;
}

bool isAlphanumericIdentifier(const char* buffer){
  int i = 0;
  while (buffer[i] != '\0') {
    if (!isalnum(buffer[i])) {
     return false;
    }
    i++;
  }
  return true;
}

// TODO: 
//    1. Create tokens for
//        a. + - * /
//        b. =
//        c. float
//        d. { }

void create_new_token(const char* buffer){
  if (!strcmp(buffer, "(")) {
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_LEFT_PARAN);
  }else if (!strcmp(buffer, ")")) {
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_RIGHT_PARAN);
  }else if (isInteger(buffer)) {
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_INT);
  }else if (isAlphanumericIdentifier(buffer)){
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_IDENTIFIER);
  }else if (!strcmp(buffer, "=")){
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_EQUAL);
  }else if (!strcmp(buffer, "+")){
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_ADD);
  }else if (!strcmp(buffer, "-")){
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_SUB);
  }else if (!strcmp(buffer, "*")){
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_MUL);
  }else if (!strcmp(buffer, "/")){
    printf("Created Token\n\tContent: %s\n\t%d\n", buffer, TOK_DIV);
  }

}
