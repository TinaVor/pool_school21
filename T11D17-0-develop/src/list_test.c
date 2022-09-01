#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void print(struct node *list) {
  while (list != NULL) {
    printf("%d\n", list->d.id);
    list = list->next;
  }
  printf("\n");
}

int main() {
  struct door dr;
  dr.id = 1;

  struct door dr1;
  dr1.id = 2;

  struct door dr2;
  dr2.id = 3;

  struct node *list = init(&dr);

  printf("\nadd_door 1, 2\n\n");
  print(list);

  struct node *list_1 = add_door(list, &dr1);
  struct node *list_2 = add_door(list_1, &dr2);

  print(list);

  if (list->d.id == 1 && list_1->d.id == 2 && list_2->d.id == 3) {
    printf("SUCCESS\n\n");
  } else {
    printf("\nFAIL\n\n");
  }

  printf("\nremove_door 2\n\n");
  print(list);

  remove_door(list_1, list);
  print(list);

  if (find_door(2, list) == 0) {
    printf("SUCCESS\n\n");
  } else {
    printf("\nFAIL\n\n");
  }

  destroy(list);

  return 0;
}
