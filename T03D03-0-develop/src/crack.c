#include <stdio.h>
int main() {
    double x, y;
    const int r = 25;
    if (scanf("%lf%lf", &x, &y) != 2) {
        printf("n/a\n");
    } else {
        if (x * x + y * y <= r) {
            printf("GOTCHA\n");
        } else
            printf("MISS\n");
    }
}

