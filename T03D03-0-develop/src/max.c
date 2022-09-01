#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b;
    char c;
    scanf("%d%d%c", &a, &b, &c);
    if (c != 10) {
        printf("n/a\n");
    } else {
        int s = max(a, b);
        printf("%d", s);
    }
}

int max(int a, int b) {
    int max_num;
    if (a > b)
        max_num = a;
    else
        max_num = b;
    return max_num;
}             
