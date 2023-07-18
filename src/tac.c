#include "tac.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TacDocument* load_tac_document(const char *src){
  FILE* file = fopen(src, "r");
  if (!file) {
    printf("Error loading file\n");
  }

  fseek(file, 0, SEEK_END);
  long fsize = ftell(file);
  fseek(file, 0, SEEK_SET);  /* same as rewind(f); */

  char *buffer = malloc(fsize + 1);
  fread(buffer, fsize, 1, file);
  fclose(file);

  buffer[fsize] = '\0';

  printf("File output: \n%s", buffer);

  TacDocument* document = (TacDocument*) malloc(sizeof(TacDocument));
  strcpy(document->src, src);
  document->buffer = buffer;
  
  tokenize_document(document);

  return document;
}

void free_tac_doc(TacDocument *doc){
  free(doc);
}
