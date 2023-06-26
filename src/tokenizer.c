#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {
  if (c == " " || c == "\t") {
    return true;
  }
  return false;
}

int non_space_char(char c) {
  if (c != " " && c != "\t") {
    return true;
  }
  return false;
}

char *token_start(char *s) {
}

char *token_terminator(char *token){
}

int count_tokens(char *s) {
}

char *copy_str(char *inStr, short len) {
}
