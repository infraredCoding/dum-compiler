#ifndef TOKEN_H

typedef enum TokenType {
  TOK_IDENTIFIER,
  TOK_INT,
  TOK_LEFT_PARAN,
  TOK_RIGHT_PARAN
} TokenType;

typedef struct Token {
  char* buffer;
  TokenType type;
} Token ;

void create_new_token(const char* buffer, TokenType type);
#endif // !TOKEN_H
