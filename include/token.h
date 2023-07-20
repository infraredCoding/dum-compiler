#ifndef TOKEN_H

typedef enum TokenType {
  TOK_IDENTIFIER,
  TOK_INT,
  TOK_LEFT_PARAN,
  TOK_RIGHT_PARAN,
  TOK_EQUAL,
  TOK_ADD,
  TOK_SUB,
  TOK_MUL,
  TOK_DIV
} TokenType;

typedef struct Token {
  char* buffer;
  TokenType type;
} Token ;

void create_new_token(const char* buffer);
#endif // !TOKEN_H
