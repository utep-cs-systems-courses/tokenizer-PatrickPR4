#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"





/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  return c == '\t' || c == ' ' ? 1 : 0;
}



/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  return !space_char(c);
}



/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str) {
  while (*str != '\0') {
    if (non_space_char(*str)) {
      return str;
    }
    str++;
  }
	
  return str;
}



/* Returns a pointer terminator char following *token */
char *token_terminator(char *token) {
  while (*token != '\0') {
    if (space_char(*token)) {
      return token;
    }
    
    token++;
  }

  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str) {
  int count = 0;
  str = token_start(str);

  while (*str != '\0') {
    count++;
    str = token_terminator(str);
    str = token_start(str);
  }

  return count;
}



/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
  char *copy_str(char *inStr, short len) {
    char *str;
    int i;

    str = (char *) malloc(len + 1);

    for(i = 0; i < len; i++) {
      str[i] = inStr[i];
    }
    
    str[i] = '\0';

    return str;


  }



/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
  char **tokenize(char* str) {
    int numWords = count_tokens(str);
    char **tokens = malloc((numWords + 1) * sizeof(char *));
    char *temp;

    for (int i = 0; i < numWords; i++) {
      str = token_start(str);
      int count = 0;
      temp = str;

      while (non_space_char(*temp) && *temp != '\0') {
	count++;
	temp++;
      }

      tokens[i] = copy_str(str, count);
      str = token_terminator(str);
    }

    tokens[numWords] = '\0';
    return tokens;
  }

 
    
/* Prints all tokens. */
  void print_tokens(char **tokens) {
    for (int i = 0; *(tokens + i) != 0; i++) {
      printf("tokens[%d] = ", i);
      printf("%s\n", *(tokens + i));
    }
  }



/* Frees all tokens and the vector containing themx. */
  void free_tokens(char **tokens) {
    for (int i = 0; ; i++) {
      if (tokens[i] == NULL) {
	return;
      }

      free(tokens[i]);
      tokens[i] = NULL;
    }

    free(tokens);
    tokens = NULL;
  }
