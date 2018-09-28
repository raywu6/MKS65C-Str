#include <stdio.h>
#include <string.h>

int mystrlen(char * s) {
  int retInt = 0;

  while (*s++) {
    retInt++;
  }
  
  return retInt;
}

int main() {
  char * s0   = "hello";
  char s1[10] = "goodbye";
  
  printf("Testing strlen():\n");
  printf("[standard]: %lu\n", strlen(s0));
  printf("[mine]: %d\n\n", mystrlen(s0));

  printf("[standard]: %lu\n", strlen(s1));
  printf("[mine]: %d\n\n", mystrlen(s1));

  return 0;
}
