#include <math.h>
#include <stdio.h>

int main() {
    double x;
    if (scanf("%lf", &x) != 1) {
        printf("n/a\n");
    } else {
        double total = 7e-3 * pow(x, 4) + ((22.8 * pow(x, (1 / 3)) - 1e3) * x + 3) / (x * (x / 2)) -
                       x * pow((10 + x), (2 / x)) - 1.01;
        printf("%.1lf", total);
    }
}
