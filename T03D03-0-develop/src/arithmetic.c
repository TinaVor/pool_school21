#include <stdio.h>

int sum(int a, int b);
int raz(int a, int b);
int ymn(int a, int b);
int del(int a, int b);

int main() {
    int a, b;
    char c;
    scanf("%d%d%c", &a, &b, &c);
    if (c != 10) {
        printf("n/a\n");
    } else {
        int s = sum(a, b);
        int r = raz(a, b);
        int y = ymn(a, b);

        if (b != 0) {
            int d = del(a, b);
            printf("%d %d %d %d\n", s, r, y, d);
        } else {
            printf("%d %d %d n/a\n", s, r, y);
        }
    }
}

int sum(int a, int b) { return (a + b); }

int raz(int a, int b) { return (a - b); }

int ymn(int a, int b) { return (a * b); }

int del(int a, int b) { return (a / b); }% 
