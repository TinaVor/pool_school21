#include <math.h>
#include <stdio.h>
#define NMAX 30
int input(int *a, int *n);

double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int *a, int n, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  if (input(data, &n) != 1) {
    output_result(data, n, mean(data, n), variance(data, n));
  } else {
    printf("n/a");
  }
  return 0;
}

void output_result(int *a, int n, double mean_v, double variance_v) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0 && (a[i] == mean_v || a[i] >= mean_v ||
                          a[i] <= mean_v + 3 * sqrt(variance_v)))
      total = a[i];
  }
  printf("%d", total);
}

int input(int *a, int *n) {
  if (scanf("%d", n) != 1)
    return 1;
  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) != 1)
      return 1;
  }
  return 0;
}

double mean(int *a, int n) {
  double count_sum = 0;
  double mean_v = 0;
  for (int i = 0; i < n; i++) {
    count_sum += a[i];
  }
  mean_v = count_sum / n;
  return mean_v;
}

double variance(int *a, int n) {
  double variance_v = 0;
  double sr = mean(a, n);
  double dis = 0;
  for (int i = 0; i < n; i++) {
    dis += ((a[i] - sr) * (a[i] - sr));
  }
  variance_v = dis / n;
  return variance_v;
}
