#include <stdio.h>
#include <string.h>

int myStrLen(char * s) {
  unsigned int retInt = 0;

  while (*s++) {
    retInt++;
  }
  
  return retInt;
}

int main() {
  char * s1 = "hello";

  printf( "%d\n" , myStrLen(s1) );
  
  return 0;
}
