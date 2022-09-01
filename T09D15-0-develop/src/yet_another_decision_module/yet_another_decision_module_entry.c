#include "../data_libs/data_io.h"
#include "decision.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
  double *data;
  int n;

  if (scanf("%d", &n) == 1 && n > 0) {
    data = malloc(n * sizeof(double));
    if (input(data, &n) == 0) {
      if (make_decision(data, n)) {
        printf("YES");
      } else {
        printf("NO");
      }
      free(data);
    } else {
      printf("n/a");
    }
    free(data);
  } else {
    printf("n/a");
  }
}
