#include <stdio.h>
#define NMAX 10
int input(int *a);
void quicksort(int *a, int, int);
void output(int *a);
int main() {
  int data[NMAX];
  int prov = input(data);
  if (prov != 1) {
    quicksort(data, 0, 9);
    output(data);
  } else {
    printf("n/a");
  }
  return 0;
}
int input(int *a) {
  int prov = 0;
  for (int *p = a; p - a < 10; p++) {
    if (scanf("%d", p) != 1)
      prov = 1;
  }
  return prov;
}
void quicksort(int *a, int first, int last) {
  if (first < last) {
    int left = first, right = last, middle = a[(left + right) / 2];
    do {
      while (a[left] < middle)
        left++;
      while (a[right] > middle)
        right--;
      if (left <= right) {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
      }
    } while (left <= right);
    quicksort(a, first, right);
    quicksort(a, left, last);
  }
}
void output(int *a) {
  for (int *i = a; i - a < 10; i++) {
    printf("%d ", *i);
  }
}
