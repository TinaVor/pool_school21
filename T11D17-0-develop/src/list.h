#ifndef SRC_DOOR_LIST_H_
#define SRC_DOOR_LIST_H_

struct door {
  int id;
  int status;
};

struct node {
  struct door d;
  struct node *next;
};

struct node *init(const struct door *door);
struct node *add_door(struct node *elem, struct door *d);
struct node *find_door(int door_id, struct node *root);
struct node *remove_door(struct node *elem, struct node *root);
void destroy(struct node *root);

#endif //  SRC_DOOR_LIST_H_
