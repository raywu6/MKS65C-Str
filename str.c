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

int mystrcmp ( char * s0, char * s1 ) {

  while ( *s0 || *s1 ) {  // both chars are not NUL
    if ( *s0 < *s1 )
      return -1;
    else if ( *s0 > *s1 )
      return 1;
    else {
      s0++;
      s1++;
    }
  }

  return 0;
}

int main() {
  char s0[32] = "hello";
  char s1[32] = "goodbye";
  char s2[32] = "test";
  char s3[32] = "hell";

  printf("Testing strlen():\n");
  printf("\t[standard]: %lu\n", strlen(s0));
  printf("\t[mine]: %d\n\n", mystrlen(s0));

  printf("\t[standard]: %lu\n", strlen(s1));
  printf("\t[mine]: %d\n\n", mystrlen(s1));

  printf("Testing strcpy():\n");
  printf("\t[standard]: %s\n", strcpy(s2,s1) );
  strcpy(s2, "test");   // reset
  printf("\t[mine]: %s\n\n", mystrcpy(s2,s1) );
  strcpy(s2, "test");   // reset
  
  printf("Testing strncat():\n");
  printf("\t[standard]: %s\n", strncat(s0,s1,7) );
  strcpy(s0, "hello");  // reset
  printf("\t[mine]: %s\n", mystrncat(s0,s1,7) );
  strcpy(s0, "hello");  // reset

  printf("\t[standard]: %s\n", strncat(s0,s1,3) );
  strcpy(s0, "hello");  // reset
  printf("\t[mine]: %s\n\n", mystrncat(s0,s1,3) );
  strcpy(s0, "hello");  // reset

  printf("Testing strcmp():\n");
  printf("\t[standard]: %d\n", strcmp(s0,s2) );
  printf("\t[mine]: %d\n\n", mystrcmp(s0,s2) );
  
  printf("\t[standard]: %d\n", strcmp(s0,s1) );
  printf("\t[mine]: %d\n\n", mystrcmp(s0,s1) );
  
  printf("\t[standard]: %d\n", strcmp(s0,s0) );
  printf("\t[mine]: %d\n\n", mystrcmp(s0,s0) );
  
  printf("\t[standard]: %d\n", strcmp(s3,s0) );
  printf("\t[mine]: %d\n\n", mystrcmp(s3,s0) );

  
  return 0;
}
