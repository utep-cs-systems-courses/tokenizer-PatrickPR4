#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main() {
  List *history = init_history();


  while (1) {
      printf("Press 't' to tokenize, 'h' to view history, 'n' followed by a number to recall a specific history, or 'q' to quit\n");

      char input[10];
      fgets(input, 10, stdin);

      switch (input[0]) {

      case 't':
	printf("Enter a sentence to tokenize: \n");
	char str [100];
	fgets(str, 100, stdin);
	char **tokens = tokenize(str);

	print_tokens(tokens);
	add_history(history, str);
	print_history(history);
	break;

      case 'h':
	print_history(history);
	free_history(history);
	break;

      case 'n':
	printf("\nEnter history number: ");
	int num = atoi(input+1);
	printf("%s",get_history(history, num));
      case 'q':
	return 0;

      default:
        printf("Invalid input");
        break;
      }
   }
}

