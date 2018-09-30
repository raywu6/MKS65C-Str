#include <stdio.h>
#include <string.h>

// returns the length of a string (w/o \0)
int mystrlen(char * str) {
  int retInt = 0;

  while (*str++) {
    retInt++;
  }
  
  return retInt;
}

// copies source string into the destination string
// returns the char pointer to destination str
char * mystrcpy ( char * dest, char * src) {
  int i = 0;
  int len = mystrlen(src);
  for(; i < len; i++){
    dest[i] = src[i];
  }
  return dest;
}

// concatenates n characters from source str to dest str
// returns the char pointer to destination str
char * mystrncat ( char * dest, char * src , int n ) {
  int dest_orig_length = mystrlen(dest);
  int  src_orig_length = mystrlen(src);
  
  int i;
  for ( i=0 ; i<n ; i++ ) {
    dest[ dest_orig_length + i ] = src[i];
  }
  
  return dest;
}

// compares two strings
// returns -1 (negative) if s0 < s1,
//          0            if s0 = s1,
//          1 (positive) if s0 > s1
int mystrcmp ( char * s0, char * s1 ) {

  while ( *s0 || *s1 ) {  // both chars are not NUL
    
    if ( (int)*s0 < (int)*s1 )      // compare ascii
      return -1;
    else if ( (int)*s0 > (int)*s1 ) // compare ascii
      return 1;
    else {
      s0++;
      s1++;
    }
  }

  return 0;
}

// returns char pointer to first occurrence of specified character in string,
//         if not found, return NULL
char * mystrchr ( char * s , int character ) {
  int size = strlen(s);

  int i; 
  for ( i=0 ; i<=size ; i++ ) {     // allow to check for ending \0
    if ( (int) *s == character ) {  // are ascii equal?
      return s;
    }
    else
      s++;
  }

  return NULL;
}

// returns char pointer to first character of specified str in str,
//         if specified str is not found, return NULL
char * mystrstr ( char * str , char * substr ) {
  int size = strlen(str);
  char * firstCharInSubstr = substr;
  char * retCharPointer = NULL;  // default

  int i;
  for ( i=0 ; i<=size ; i++ ) { // allow to check for ending \0
                                // will account for different len strs

    if ( *str == *substr ) { // if current corresponding chars ==
      if ( *str == *firstCharInSubstr ) {  // prepare...
	retCharPointer = str;
      }
      str++;
      substr++;
    }
    
    else if ( !*substr ) {    // if reached \0 in substr
      return retCharPointer;  // exhausted substr (found)
    }
    
    else {
      str++;
      retCharPointer = NULL;  // reset return val
    }
    
  } // end for-loop

  return retCharPointer;
}

int main() {
  char s0[32] = "hellow";
  char s1[32] = "goodbye";
  char s2[32] = "test";
  char s3[32] = "hell";

  printf("Testing strlen():\n");
  printf("\t[standard]: %lu\n", strlen(s0));
  printf("\t[mine]: %d\n\n", mystrlen(s0));

  printf("\t[standard]: %lu\n", strlen(s1));
  printf("\t[mine]: %d\n\n", mystrlen(s1));

  // ========== LINE OF DEMARCATION ==========

  printf("Testing strcpy():\n");
  printf("\t[standard]: %s\n", strcpy(s2,s1) );
  strcpy(s2, "test");   // reset
  printf("\t[mine]: %s\n\n", mystrcpy(s2,s1) );
  strcpy(s2, "test");   // reset
  
  printf("\t[standard]: %s\n", strcpy(s1,s2) );
  strcpy(s2, "test");   // reset
  printf("\t[mine]: %s\n\n", mystrcpy(s1,s2) );
  strcpy(s2, "test");   // reset

  // ========== LINE OF DEMARCATION ==========
  
  printf("Testing strncat():\n");
  printf("\t[standard]: %s\n", strncat(s0,s1,7) );
  strcpy(s0, "hellow");  // reset
  printf("\t[mine]: %s\n", mystrncat(s0,s1,7) );
  strcpy(s0, "hellow");  // reset

  printf("\t[standard]: %s\n", strncat(s0,s1,3) );
  strcpy(s0, "hellow");  // reset
  printf("\t[mine]: %s\n\n", mystrncat(s0,s1,3) );
  strcpy(s0, "hellow");  // reset

  printf("Testing strcmp():\n");
  printf("\t[standard]: %d\n", strcmp(s0,s2) );
  printf("\t[mine]: %d\n\n", mystrcmp(s0,s2) );
  
  printf("\t[standard]: %d\n", strcmp(s0,s1) );
  printf("\t[mine]: %d\n\n", mystrcmp(s0,s1) );
  
  printf("\t[standard]: %d\n", strcmp(s0,s0) );
  printf("\t[mine]: %d\n\n", mystrcmp(s0,s0) );
  
  printf("\t[standard]: %d\n", strcmp(s3,s0) );
  printf("\t[mine]: %d\n\n", mystrcmp(s3,s0) );

  // ========== LINE OF DEMARCATION ==========
  
  printf("Testing strchr():\n");
  printf("\t[standard]: %s\n", strchr(s0,0) );
  printf("\t[mine]: %s\n\n", mystrchr(s0,0) );

  printf("\t[standard]: %s\n", strchr(s0,'0') );
  printf("\t[mine]: %s\n\n", mystrchr(s0,'0') );

  printf("\t[standard]: %s\n", strchr(s1,'g') );
  printf("\t[mine]: %s\n\n", mystrchr(s1,'g') );

  printf("\t[standard]: %s\n", strchr(s2,'t') );
  printf("\t[mine]: %s\n\n", mystrchr(s2,'t') );

  // ========== LINE OF DEMARCATION ==========
  
  printf("Testing strstr():\n");
  printf("\t[standard]: %s\n", strstr(s0,s3) );
  printf("\t[mine]: %s\n\n", mystrstr(s0,s3) );

  printf("\t[standard]: %s\n", strstr(s3,s0) );
  printf("\t[mine]: %s\n\n", mystrstr(s3,s0) );

  printf("\t[standard]: %s\n", strstr(s0,s0) );
  printf("\t[mine]: %s\n\n", mystrstr(s0,s0) );

  printf("\t[standard]: %s\n", strstr(s3,s2) );
  printf("\t[mine]: %s\n\n", mystrstr(s3,s2) );
  
  return 0;
}

