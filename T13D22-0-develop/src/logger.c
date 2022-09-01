#include "logger.h"
#include "log_levels.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

FILE *log_init(char *filename);
int logcat(FILE *log_file, char *message, log_level level);
int log_close(FILE *log_file);

FILE *log_init(char *filename) {
  FILE *logfile = NULL;
  logfile = fopen(filename, "a+");

  return logfile;
}

int logcat(FILE *log_file, char *message, log_level level) {
  long int ttime;
  ttime = time(NULL);
  char mes[20];

  if (level == debug) {
    strcpy(mes, "DEBUG");
  }

  if (level == trace) {
    strcpy(mes, "TRACE");
  }

  if (level == info) {
    strcpy(mes, "INFO");
  }

  if (level == warning) {
    strcpy(mes, "WARNING");
  }

  if (level == error) {
    strcpy(mes, "ERROR");
  }

  fprintf(log_file, "%s %s\b %s\n", mes, ctime(&ttime), message);
  return 0;
}

int log_close(FILE *log_file) {
  int result = 0;

  if (log_file) {
    fclose(log_file);
  } else {
    result = 1;
  }
  return result;
}
