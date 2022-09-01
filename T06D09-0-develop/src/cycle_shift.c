#include <stdio.h>
#define NMAX 10
int input(int *A, int *n, int *c);
void output(int *A, int n);
void Reverse(int *A, int *n);

int main() {
  int n, c, A[NMAX];
  if (input(A, &n, &c) != 1) {
    Reverse(&A[0], &A[c - 1]);
    Reverse(&A[c], &A[n - 1]);
    Reverse(&A[0], &A[n - 1]);
    output(A, n);

  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *A, int *n, int *c) {
  if (scanf("%d", n) != 1)
    return 1;
  for (int *p = A; p - A < *n; p++) {
    if (scanf("%d", p) != 1)
      return 1;
  }
  if (scanf("%d", c) != 1)
    return 1;
  if (*c < 0) {
    *c = *c * (-1);
  }
  return 0;
}
void output(int *A, int n) {
  for (int *i = A; i - A < n; i++) {
    printf("%d ", *i);
  }
  printf("\n");
}

void Reverse(int *A, int *n) {
  int temp;
  while (n > A) {
    temp = *A;
    *A = *n;
    *n = temp;
    A++;
    n--;
  }
}
