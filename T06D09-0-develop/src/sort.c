#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
  int data[NMAX];
  if (input(data) != 1) {
    sort(data);
    output(data);
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *a) {
  for (int *p = a; p - a < 10; p++) {
    if (scanf("%d", p) != 1)
      return 1;
  }
  return 0;
}

void sort(int *a) {
  for (int i = 0; i < 10 - 1; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

void output(int *a) {
  for (int *i = a; i - a < 10; i++) {
    printf("%d ", *i);
  }
}
