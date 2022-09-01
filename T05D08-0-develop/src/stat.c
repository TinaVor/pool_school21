#include <math.h>
#include <stdio.h>
#define NMAX 10
int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  if (input(data, &n) != 1) {
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

  } else {
    printf("n/a");
  }
  return 0;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d %d %lf %lf ", max_v, min_v, mean_v, variance_v);
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
void output(int *a, int n) {
  for (int *i = a; i - a < n; i++) {
    printf("%d ", *i);
  }
  printf("\n");
}

int max(int *a, int n) {
  int max_v = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > max_v) {
      max_v = a[i];
    }
  }
  return max_v;
}

int min(int *a, int n) {
  int min_v = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] < min_v) {
      min_v = a[i];
    }
  }
  return min_v;
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
