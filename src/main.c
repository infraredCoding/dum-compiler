#include "tac.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("========Loading Tac File=======\n");
  TacDocument* doc = load_tac_document("./test/main.tac");
  free_tac_doc(doc);
  return 1;
}
