#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
  char string[100];
  
  printf("$ ");
  fgets(string,100, stdin);
  printf("%s\n", string);
  
  return(0);
}
