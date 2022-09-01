#define length 10
#define new_length 10
#include <stdio.h>

int input(int *buffer, int *length);
void output(int *buffer, int *length);
int sum_numbers(int *buffer, int length);
int new_length_mass(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
  int length;
  if (scanf("%d", &length) == 1 && length <= 10) {
    int buffer[length];
    int prov = input(buffer, &length);
    if (prov != 1) {
      int sum = sum_numbers(buffer, length);
      if (sum != 0) {
        int new_length = new_length_mass(buffer, length);
        int numbers[new_length];
        find_numbers(buffer, length, sum, numbers);
        output(numbers, &new_length);
      } else {
          printf("n/a");
      }
    } else {
        printf("n/a");
    }
  } else {
      printf("n/a");
  }
}

int sum_numbers(int *buffer, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0)
      sum = sum + buffer[i];
  }
  return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
  printf("%d ", number);
  int t = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] != 0 && number % buffer[i] == 0) {
      numbers[t] = buffer[i];
      t++;
    }
  }
  return 0;
}

int new_length_mass(int *buffer, int length) {
  int new_length = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0)
      new_length++;
  }
  return new_length;
}

int input(int *buffer, int *length) {
  int prov = 0;
  for (int i = 0; i < *length; i++) {
    if (scanf("%d", &buffer[i]) != 1)
      prov = 1;
  }
  return prov;
}

void output(int *buffer, int *length) {
  for (int i = 0; i < *length; i++) {
    printf("%d ", buffer[i]);
  }
}
