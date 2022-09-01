#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} data;

void print_file(FILE *file, char *path);
int sort_f(FILE *file, char *path);
int add_str(FILE *file, char *path);

char *read_str(FILE *stream);
void menu();

int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
data read_record_from_file(FILE *pfile, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile, const data *record_to_write, int index);

int main() {
    menu();
    return 0;
}

void menu() {
    int command = 0;
    char *path = read_str(stdin);
    FILE* f;
    f = fopen(path, "rb+");
    if (f != NULL) {
        scanf("%d", &command);
        if (getchar() != '\n') {
            printf("n/a\n");
            char ch = getchar();
            while (ch != ' ' && ch != '\n') {
                ch = getchar();
            }
        } else {
            if (command == 0) {
                print_file(f, path);
            } else if (command == 1) {
                 sort_f(f, path);
                 print_file(f, path);
            } else if (command == 2) {
                add_str(f, path);
                sort_f(f, path);
                print_file(f, path);
            } else {
                printf("n/a\n");
            }
        }
    } else {
        printf("n/a\n");
    }
    free(path);
}


void print_file(FILE *f, char *path) {
    if ((f = fopen(path, "rb")) == NULL) {
        printf("n/a");
    } else {
        data entry_date;
        int size = get_records_count_in_file(f);

        for (int i = 0; i < size; i++) {
            entry_date = read_record_from_file(f, i);

            printf("%d %d %d %d %d %d %d %d\n", entry_date.year, entry_date.month, entry_date.day, \
            entry_date.hour, entry_date.minute, entry_date.second, entry_date.status, entry_date.code);
        }

        fclose(f);
    }
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

int sort_f(FILE *f, char *path) {
    if ((f = fopen(path, "rb+")) == NULL) {
        printf("n/a");
    } else {
        int size = get_records_count_in_file(f);

        for (int i = 0; i < size; i++) {
            int min = i;

            for (int j = i; j < size; j++) {
                char str_min[100];
                char str_j[100];

                data entry_min = read_record_from_file(f, min);
                data entry_j = read_record_from_file(f, j);

                sprintf(str_min, "%04d %02d %02d %02d %02d %02d %01d %03d", entry_min.year, entry_min.month,
                entry_min.day, entry_min.hour, entry_min.minute, entry_min.second,
                entry_min.status, entry_min.code);

                sprintf(str_j, "%04d %02d %02d %02d %02d %02d %01d %03d", entry_j.year, entry_j.month,
                entry_j.day, entry_j.hour, entry_j.minute, entry_j.second, entry_j.status, entry_j.code);

                int res = strcmp(str_min, str_j);

                if (res > 0) {
                    min = j;
                }
            }

            swap_records_in_file(f, i, min);
        }

        fclose(f);
    }

    return 0;
}

int add_str(FILE *file, char *path) {
    char str[1024];
    struct date new_entry;

    fgets(str, 1023, stdin);

    if (sscanf(str, "%d %d %d %d %d %d %d %d", &new_entry.year, &new_entry.month, &new_entry.day, \
    &new_entry.hour, &new_entry.minute, &new_entry.second, &new_entry.status, &new_entry.code) != 8) {
        printf("n/a");
    }

    if ((file = fopen(path, "rb+")) == NULL) {
        printf("n/a");
    } else {
        int records_num = get_records_count_in_file(file);

        write_record_in_file(file, &new_entry, records_num);

        fclose(file);
    }

    return 0;
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct date record1 = read_record_from_file(pfile, record_index1);
    struct date record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

void write_record_in_file(FILE *pfile, const struct date *record_to_write, int index) {
    int offset = index * sizeof(struct date);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct date), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct date);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);

    return size;
}

struct date read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct date);
    fseek(pfile, offset, SEEK_SET);
    struct date record;
    fread(&record, sizeof(struct date), 1, pfile);
    rewind(pfile);

    return record;
}
