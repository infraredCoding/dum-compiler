#ifndef TAC_H

typedef struct TacDoc {
  char* src;
  char* buffer;
} TacDocument;

TacDocument* load_tac_document(const char* src);
void free_tac_doc(TacDocument* doc);

#endif // !TAC_H
