#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
  int n, data[NMAX];
  if (input(data, &n) != 1) {
    squaring(data, &n);
    output(data, &n);
  } else {
    printf("n/a");
  }

  return 0;
}

int input(int *a, int *n) {
  if (scanf("%d", n) != 1)
    return 1;

  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) != 1)
      return 1;
  }
}

void output(int *a, int *n) {
  for (int *i = a; i - a < *n; i++) {
    printf("%d", *i);
  }
}

void squaring(int *a, int *n) {
  for (int *i = a; i - a < *n; i++) {
    *i *= *i;
  }
}
