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
  char **ps = 0;
  while (space_char(*s)) {
    s++;
  }

  if (non_space_char(*s)) {
    ps = s;
  }

  return ps;
}

char *token_terminator(char *token){
  while (non_space_char(*token)) {

    if (space_char(token + 1)) {
      return token;
    }

    token++;
  }
}

int count_tokens(char *s) {
}

char *copy_str(char *inStr, short len) {
}
//run through string twice: first to count words, second to copy each word as token
//use token_start & token_terminator to count words and copy
//
