#include <stdio.h>
#include <stdlib.h>
#define H 100
#define W 100

int **alloc(int N, int M, int variant) {
  int **A;
  if (variant == 2) {
    A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
      A[i] = (int *)malloc(M * sizeof(int));
    }
  }
  if (variant == 3) {
    A = (int **)malloc(N * sizeof(int *) + N * M * sizeof(int));
    int *start = (int *)((char *)A + N * sizeof(int *));
    for (int i = 0; i < N; i++) {
      A[i] = start + i * M;
    }
  }
  if (variant == 4) {
    A = malloc(M * sizeof(int *));
    int *a = malloc(M * N * sizeof(int));
    for (int i = 0; i < M; i++) {
      A[i] = a + N * i;
    }
  }
  return A;
}
void fre(int **A, int N, int variant) {
  if (variant == 2) {
    for (int i = 0; i < N; i++) {
      free(A[i]);
    }
    free(A);
  }
  if (variant == 3 || variant == 4) {
    free(A);
  }
}
void print(int **A, int N, int M, int variant) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  fre(A, N, variant);
}

void start(int N, int M, int variant) {
  int prov = 0;
  int **A = alloc(N, M, variant);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (scanf("%d", &A[i][j]) != 1) {
        prov = 1;
      }
    }
  }
  if (prov == 0) {
    print(A, N, M, variant);
  } else {
    printf("n/a");
  }
}

void print1(int A[][W], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

void start1(int N, int n, int m) {
  int A[N][W];
  int prov = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (scanf("%d", &A[i][j]) != 1) {
        prov = 1;
      }
    }
  }
  if (prov == 0)
    print1(A, n, m);
  else
    printf("n/a");
}

int main() {
  int N, M, variant;
  if (scanf("%d", &variant) == 1) {
    switch (variant) {
    case 1:
      if (scanf("%d%d", &N, &M) == 2)
        start1(H, N, M);
      else
        printf("n/a");
      break;
    case 2:
      if (scanf("%d%d", &N, &M) == 2)
        start(N, M, variant);
      else
        printf("n/a");
      break;
    case 3:
      if (scanf("%d%d", &N, &M) == 2)
        start(N, M, variant);
      else
        printf("n/a");
      break;
    case 4:
      if (scanf("%d%d", &N, &M) == 2)
        start(N, M, variant);
      else
        printf("n/a");
      break;
    }
  } else {
    printf("n/a");
  }
  return 0;
}
