#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node *init(const struct door *door) {
  struct node *result;
  result = malloc(sizeof(struct node));
  result->d = *door;
  result->next = NULL;

  return result;
}

struct node *add_door(struct node *elem, struct door *d) {
  struct node *result = init(d);
  result->next = elem->next;
  elem->next = result;

  return result;
}

struct node *find_door(int door_id, struct node *root) {
  int flag = 0;
  struct node *result = NULL;
  while (root != NULL && flag == 0) {
    if (root->d.id == door_id) {
      result = root;
      flag = 1;
    }
    root = root->next;
  }
  return result;
}

struct node *remove_door(struct node *elem, struct node *root) {
  struct node *result;
  result = root;
  while (result->next != elem) {
    result = result->next;
  }
  result->next = elem->next;
  free(elem);
  return elem;
}

void destroy(struct node *root) {
  struct node *result;
  result = root;
  while (result != NULL) {
    struct node *new = result;
    result = result->next;
    free(new);
  }
}
