#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void read();

int main() {
  menu();
  return 0;
}

void menu() {
  int command = 0;

  while (command != -1) {
    scanf("%d", &command);
    if (getchar() != '\n') {
        printf("n/a");
        char ch = getchar();
        while (ch != ' ' && ch != '\n') {
          ch = getchar();
        }
    }else {
      if (command == 1) {
        read();
      } else {
        printf("n/a\n");
    }
  }
}
}


void read() {
  char *str = NULL;
  size_t size = 0;
  getline(&str, &size, stdin);

  size_t l = strlen(str);
  str[l - 1] = 0;

  FILE *f;
  f = fopen(str, "r");
  if (f == NULL) {
    printf("n/a\n");
  } else {
    char c = fgetc(f);
    if (c == -1) {
        printf("n/a\n");
    } else {
        while (c != -1) {
            printf("%c", c);
            c = fgetc(f);
            }
        }
        free(str);
    }
}