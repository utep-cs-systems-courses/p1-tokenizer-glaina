#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(int argc, char **argv) {
  List *history = init_history();
  char *quit = "exit";
  char *hist = "history";

  while (1) {
    char string[100];
    printf(string, 100, stdin);
    fgets(string, 100, stdin);
    
    if (str_cmp(string, quit) == 0) {
      free_history(history);
      break;
    }
    else if (str_cmp(string, hist) == 0) {
      print_history(history);
    }
    else {
      char **tv = tokenize(string);
      print_tokens(tv);
      free_tokens(tv);
      add_history(history, string);
    }
  }

  return 0;
}
