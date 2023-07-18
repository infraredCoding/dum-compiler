#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lexer* new_lexer(char* src) {
  Lexer* lexer = (Lexer*) malloc(sizeof(Lexer));
  lexer->src = src;
  lexer->size = strlen(src);
  lexer->index = 0;
  return lexer;
}

void free_lexer(Lexer *lexer){
  free(lexer);
}

void tokenize_document(TacDocument* tac){
  Lexer* lexer = new_lexer(tac->buffer);
  printf("Lexer %s\n", lexer->src);
  char buffer[256];
  int i = 0; // index of the particular word/symbol/token
  int lexi = 0; // index of the lexer in whole document
  
  while (lexer->src[lexi] != '\0') {

    if (lexer->src[lexi] == ' ' || lexer->src[lexi] == '\n'){
      memset(buffer, 0, sizeof(buffer));
      lexi++;
      i = 0;
    }else if (lexer->src[lexi] == '(') {
      
      printf("\tnew token: %s\n", buffer);
      printf("\tnew token: (\n");
      lexi++;
      i = 0;
      memset(buffer, 0, sizeof(buffer));

      while (lexer->src[lexi] != ')') {
        if (lexer->src[lexi] == '\0') {
          printf("Syntax error: unclosed paranthesis - ')' expected\n");
          break;
        }
        buffer[i] = lexer->src[lexi];
        i++;
        lexi++;
      }

      printf("\tnew token: %s\n", buffer);
      memset(buffer, 0, sizeof(buffer));
      lexi++;
      i = 0;
      printf("\tnew token: )\n");
    }else {
        buffer[i] = lexer->src[lexi];
        i++;
        lexi++;
    }
  }
  free_lexer(lexer);
}

