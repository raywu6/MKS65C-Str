#include <stdio.h>
#include <string.h>

int mystrlen(char * s) {
  int retInt = 0;

  while (*s++) {
    retInt++;
  }
  
  return retInt;
}

char * mystrcpy ( char * s1, char * s2){
  int i = 0;
  int len = mystrlen(s2);
  for(; i < len; i++){
    s1[i] = s2[i];
  }
  return s1;
}

int main() {
  char s0[10] = "hello";
  char s1[10] = "goodbye";
  char s2[10] = "test";

  printf("s0 = %s\n", s0);
  printf("s1 = %s\n\n", s1);
  
  printf("Testing strlen():\n");
  printf("[standard]: %lu\n", strlen(s0));
  printf("[mine]: %d\n\n", mystrlen(s0));

  printf("[standard]: %lu\n", strlen(s1));
  printf("[mine]: %d\n\n", mystrlen(s1));

  printf("s2 = %s\n\n", s2);

  printf("Testing strcpy():\n");
  printf("[standard]: %s\n", strcpy(s2, s1));
  printf("[reset]: %s\n", strcpy(s2, "test"));
  printf("[mine]: %s\n", strcpy(s2, s1));

  return 0;
}
