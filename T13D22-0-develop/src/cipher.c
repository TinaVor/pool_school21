#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LOG
#include "log_levels.h"
#include "logger.h"
#endif

void menu();
void read(char *str);
char *read_str(FILE *stream);
void add(char *path);
void find_files(char *str);
char *path_f(char *str, struct dirent *ent);
void cipher(char *path, int shift);

// int logcat(FILE* log_file, char *message, log_level level);

int main() {
  menu();
  return 0;
}

void menu() {
#ifdef LOG
  FILE *f_log;
  f_log = log_init("log_f.log");
#endif

  int command = 0;
  char *path = NULL;
  #ifdef LOG
      logcat(f_log, "START", info);
    #endif

  while (command != -1) {
    scanf("%d", &command);

    if (getchar() != '\n') {
      printf("n/a\n");
      char ch = getchar();
      while (ch != ' ' && ch != '\n') {
        ch = getchar();
      }
    } else {
      if (command == 1) {
        char *str = read_str(stdin);
        path = str;
        read(str);
      } else if (command == 2) {
        add(path);
        read(path);
      } else if (command == 3) {
        char *str = read_str(stdin);
        FILE *f;
        f = fopen(str, "r");
        if (f != NULL) {
          find_files(str);
        } else {
          printf("n/a\n");

#ifdef LOG
          logcat(f_log, "ОШИБКА", error);
#endif
        }
        free(str);
      } else {
        if (command != -1) {
          printf("n/a\n");
#ifdef LOG
          logcat(f_log, "ОШИБКА", error);
#endif
        }
      }
    }
  }
  if (path != NULL) {
    free(path);
  }

#ifdef LOG
  logcat(f_log, "FINISH", info);
  log_close(f_log);
#endif
}

void read(char *str) {
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
    printf("\n");
  }
  fclose(f);
}

char *read_str(FILE *stream) {
  char *str = NULL;
  size_t size = 0;
  if (getline(&str, &size, stream) != -1) {
    size_t l = strlen(str);
    str[l - 1] = 0;
  } else {
    free(str);
    str = NULL;
  }
  return str;
}

void add(char *path) {
  FILE *f;
  f = fopen(path, "a+");
  char *str = read_str(stdin);
  if (str != NULL && f != NULL) {
    fprintf(f, "\n%s", str);
    fclose(f);

  } else {
    printf("n/a\n");
  }
  free(str);
}

void find_files(char *str) {
  FILE *f;
  DIR *dir;
  struct dirent *ent;
  int shift;
  scanf("%d", &shift);

  if ((dir = opendir(str)) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      strtok(ent->d_name, ".");
      char *ptr2 = strtok(NULL, ".");
      if (ptr2 != NULL) {
        int rn = strcmp(ptr2, "c");
        if (rn == 0) {
          char *path = path_f(str, ent);
          strcat(path, ".c");
          cipher(path, shift);
          free(path);
        }
        rn = strcmp(ptr2, "h");
        if (rn == 0) {
          char *path = path_f(str, ent);
          strcat(path, ".h");
          f = fopen(path, "w");
          fclose(f);
          free(path);
        }
      }
    }
    closedir(dir);
  }
}

char *path_f(char *str, struct dirent *ent) {
  char *path = calloc(ent->d_namlen + strlen(str) + 2, sizeof(char));
  strcat(path, str);
  strcat(path, "/");
  strcat(path, ent->d_name);
  return path;
}

void cipher(char *path, int shift) {
  FILE *f, *f_2;
  f = fopen(path, "r");
  f_2 = fopen("a.out", "a+");
  int flag = 0;
  int ENG = 26;
  char c = getc(f);

  while (c != EOF) {
    flag = 0;
    if (c >= 'A' && c <= 'Z') {
      c = c + (shift % ENG);
      if (c > 'Z')
        c = 'A' + (c - 'Z') - 1;
      fprintf(f_2, "%c", c);
      flag = 1;
    }
    if (c >= 'a' && c <= 'z') {
      c = c + (shift % ENG);
      if (c > 'z')
        c = 'a' + (c - 'z') - 1;
      fprintf(f_2, "%c", c);
      flag = 1;
    }
    if (!flag)
      fprintf(f_2, "%c", c);
    c = getc(f);
  }

  fclose(f);
  fclose(f_2);
  remove(path);
  rename("a.out", path);
}
