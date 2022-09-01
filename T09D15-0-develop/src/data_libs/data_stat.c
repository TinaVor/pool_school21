#include "data_stat.h"

double max(double *data, int n) {
  int max_v = data[0];
  for (int i = 0; i < n; i++) {
    if (data[i] > max_v) {
      max_v = data[i];
    }
  }
  return max_v;
}

double min(double *data, int n) {
  int min_v = data[0];
  for (int i = 0; i < n; i++) {
    if (data[i] < min_v) {
      min_v = data[i];
    }
  }
  return min_v;
}

double mean(double *data, int n) {
  double count_sum = 0;
  double mean_v = 0;
  for (int i = 0; i < n; i++) {
    count_sum += data[i];
  }
  mean_v = count_sum / n;
  return mean_v;
}

double variance(double *data, int n) {
  double variance_v = 0;
  double sr = mean(data, n);
  double dis = 0;
  for (int i = 0; i < n; i++) {
    dis += ((data[i] - sr) * (data[i] - sr));
  }
  variance_v = dis / n;
  return variance_v;
}
