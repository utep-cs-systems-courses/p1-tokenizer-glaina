#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  Item *new_item = list->root;
  int num = 1;

  while (new_item->next != 0) {
    new_item = new_item->next;
    num++;
  }

  if (num == 1) {
    new_item->id = num;
    new_item->str = str;
  }

  new_item->next = malloc(sizeof(Item));
  new_item->next->id = num;
  new_item->next->str = str;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *temp = list->root;
  int count = 1;

  while (count != id) {
    temp = temp->next;
    count++;
  }

  return temp->str;
}

/*Print the entire contents of the list. */
void print_history(List *list) {
  Item *temp = list->root->next;

  while (temp != 0) {
    printf("%d\t", temp->id);
    puts(temp->str);
    printf("\n");
    temp = temp->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list) {
  Item *temp = list->root;

  while (temp != 0) {
    Item *curr = temp;
    temp = temp->next;
    free(curr);
  }
  free(list);
}
