#include<stdio.h>

  int del(int n);

  int main() {
    int n;
    char c;
    scanf("%d%c", &n, &c);

    if (c != '\n') {
      printf("n/a\n");
    } else {
        int d;
        del(n);
      }

    return 0;
}

  int del(int n) {
    long long fib = 0, a = 0, b = 1;
    for (int i = 0; i < n; i++)
        a = b, b = fib, fib = a+b;
    printf("%lld\n", fib);

    return 0;
}
