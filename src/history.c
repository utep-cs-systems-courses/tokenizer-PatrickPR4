#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"



/* Initialize the linked list to keep the history. */
List* init_history() {
  List *history = malloc(sizeof(List));
  history->root = malloc(sizeof(Item));
  
  return history;

}



/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {}

  char *s = copy_str(str, i);
  int count = 1;
  Item *curr = list -> root;

  if (curr == NULL) {
    curr = malloc(sizeof(Item));
    curr->id = 0;
    curr->str = s;
    curr->next = NULL;
    list->root = curr;
    return;
  }

  while (curr->next != NULL) {
    count++;
    curr = curr->next;
  }


  curr->next = malloc(sizeof(Item));
  curr->next->id = count;
  curr->next->str = s;
  curr->next->next = NULL;

}



/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *curr = list->root;

  while (curr != NULL) {
    if (curr->id == id) {
      return curr->str;
    }
    curr = curr->next;
  }
  return " ";
}



/*Print the entire contents of the list. */
void print_history(List *list) {
  Item *curr = list->root;
  while (curr != NULL) {
    printf("%d.- %s\n", curr->id, curr->str);
    curr = curr->next;

  }
}


/*Free the history list and the strings it references. */
void free_history(List *list) {
  Item *curr = list->root;
  Item *temp = curr;

  while (curr != NULL) {
    temp = curr;
    curr = curr->next;
    free(temp);
  }

  free(list);
}
