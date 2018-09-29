#include <stdio.h>
#include <string.h>

int mystrlen(char * str) {
  int retInt = 0;

  while (*str++) {
    retInt++;
  }
  
  return retInt;
}

char * mystrcpy ( char * dest, char * src) {
  int i = 0;
  int len = mystrlen(src);
  for(; i < len; i++){
    dest[i] = src[i];
  }
  return dest;
}

char * mystrncat ( char * dest, char * src , int n ) {
  int dest_orig_length = mystrlen(dest);
  int  src_orig_length = mystrlen(src);
  
  int i;
  for ( i=0 ; i<n ; i++ ) {
    dest[ dest_orig_length + i ] = src[i];
  }
  
  return dest;
}

int main() {
  char s0[32] = "hello";
  char s1[32] = "goodbye";
  char s2[32] = "test";

  printf("Testing strlen():\n");
  printf("\t[standard]: %lu\n", strlen(s0));
  printf("\t[mine]: %d\n\n", mystrlen(s0));

  printf("\t[standard]: %lu\n", strlen(s1));
  printf("\t[mine]: %d\n\n", mystrlen(s1));

  printf("Testing strcpy():\n");
  printf("\t[standard]: %s\n", strcpy(s2,s1) );
  strcpy(s2, "test");  // reset
  printf("\t[mine]: %s\n\n", mystrcpy(s2,s1) );
  strcpy(s2, "test");  // reset
  
  printf("Testing strncat():\n");
  printf("\t[standard]: %s\n", strncat(s0,s1,7) );
  strcpy(s0, "hello");  // reset
  printf("\t[mine]: %s\n", mystrncat(s0,s1,7) );
  strcpy(s0, "hello"); // reset

  printf("\t[standard]: %s\n", strncat(s0,s1,3) );
  strcpy(s0, "hello");  // reset
  printf("\t[mine]: %s\n", mystrncat(s0,s1,3) );
  strcpy(s0, "hello"); // reset

  
  return 0;
}
