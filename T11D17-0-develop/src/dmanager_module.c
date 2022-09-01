#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void print(struct door *doors);
void sort(struct door *doors);
void close_door(struct door *doors);

int main() {
  struct door doors[DOORS_COUNT];

  initialize_doors(doors);
  sort(doors);
  close_door(doors);
  print(doors);

  return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}

void print(struct door *doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    { printf("%d, %d\n", doors[i].id, doors[i].status); }
  }
}

void sort(struct door *doors) {
  for (int i = 0; i < DOORS_COUNT - 1; i++) {
    for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
      if (doors[j].id > doors[j + 1].id) {
        int tmp = doors[j].id;
        doors[j].id = doors[j + 1].id;
        doors[j + 1].id = tmp;
      }
    }
  }
}

void close_door(struct door *doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    { doors[i].status = 0; }
  }
}
