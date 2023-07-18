#ifndef LEXER_H
#define LEXER_H

#include "tac.h"
#include <stdint.h>
#include <wchar.h>
typedef struct Lexer {
  char* src;
  uint32_t size;
  uint32_t index;
} Lexer ;

Lexer* new_lexer(char* src);
void free_lexer(Lexer* lexer);
void tokenize_document(TacDocument* tac);

#endif // !LEXER_H
