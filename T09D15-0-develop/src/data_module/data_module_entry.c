#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "data_process.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
  double *data;
  int n;
  if (scanf("%d", &n) == 1 && n > 0) {
    data = malloc(n * sizeof(double));
    if (input(data, &n) == 0) {
      if (normalization(data, n))
        output(data, n);
      else
        printf("ERROR");
    } else {
      printf("n/a");
    }
    free(data);
  } else {
    printf("n/a");
  }
}
