#include "data_process.h"
#include "../data_libs/data_stat.h"
#include <math.h>
#include <stdio.h>

int normalization(double *data, int n) {
  int result = 1;
  double max_value = max(data, n);
  double min_value = min(data, n);
  double size = max_value - min_value;

  if (fabs(size) > EPS) {
    for (int i = 0; i < n; i++) {
      data[i] = data[i] / size - min_value / size;
    }
  } else {
    result = 0;
  }

  return result;
}

void sort(double *data, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        double tmp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = tmp;
      }
    }
  }
}
