#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int str_cmp(char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

int space_char(char c) {
  if (c == ' ' || c == '\t') {
    return 1;
  }
  return 0;
}

int non_space_char(char c) {
  if (space_char(c) == 0) {
    return 1;
  }
  return 0;
}

char *token_start(char *s) {
  char **ps = 0;

  while (space_char(*s) == 1) {
    s++;
  }

  if (non_space_char(*s) == 1) {
    ps = &s;
  }

  return *ps;
}

char *token_terminator(char *token){
  char **ps = 0;
  
  while (non_space_char(*token) == 1) {
    token++;
  }

  if (space_char(*token) == 1) {
    ps = &token;
  }

  return *ps;
}

int count_tokens(char *s) {

  int count = 0;
  int tf = 0;

  while (*s != '\0') {
    if (space_char(*s) == 1) {
      tf = 0;
    }
    else if (tf == 0) {
      tf = 1;
      count++;
    }
    s++;
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *strCopy = (char*)malloc((len + 1) * sizeof(char));

  int i = 0;
  for (; i < len; i++) {
    strCopy[i] = inStr[i];
  }

  strCopy[i] = '\0';

  return strCopy;
}

char **tokenize(char *str) {
  int count = count_tokens(str);
  char **tokens = (char**)malloc((count + 1) * sizeof(char*));
  char *ptr = str;
  
  int i;
  for (i = 0; i < count; i++) {
    ptr = token_start(ptr);
    char *temp = ptr; // temp pointer to find token length
    char *end = token_terminator(temp);
    int len = end - temp;
    tokens[i] = copy_str(ptr, len);
    ptr = token_terminator(ptr);
  }
  tokens[i] = 0;
  return tokens;
}

void print_tokens(char **tokens) {
  for (int i = 0; tokens[i] != 0; i++) {
    printf("%s\n", tokens[i]);
  }
}

void free_tokens(char **tokens) {
  for (int i = 0; i != 0; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

