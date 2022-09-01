#include <stdio.h>
#include <string.h>

typedef struct date  {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
}data;

int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
data read_record_from_file(FILE *pfile, int index);
data read_record_from_file_2(FILE *pfile, int index);

int main(void) {
    FILE *file = NULL;
    data result_date;
    data search_date, entry_date;

    char f[1024];
    scanf("%1023s", f);

    while ((getchar()) != '\n') {
    }

    char str[1024];
    fgets(str, 1023, stdin);

    sscanf(str, "%2d.%2d.%4d", &search_date.day, &search_date.month, &search_date.year);
    sprintf(str, "%04d %02d %02d", search_date.year, search_date.month, search_date.day);


    if ((file = fopen(f, "rb+")) == NULL) {
        printf("n/a");
        return 1;
    }

    int entry_num = get_records_count_in_file(file);

    for (int i = 0; i < entry_num; i++) {
        entry_date = read_record_from_file(file, i);

        char str2[1024];
        sprintf(str2, "%04d %02d %02d", entry_date.year, entry_date.month, entry_date.day);

        printf("%s\n", str2);
        if (strcmp(str, str2) == 0) {
            result_date = read_record_from_file_2(file, i);
            printf("%d", result_date.code);
            fclose(file);
            return 0;
        }
    }

    printf("n/a");
    fclose(file);

    return 0;
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(data);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);

    return size;
}

data read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(data);
    fseek(pfile, offset, SEEK_SET);
    data record;
    fread(&record, sizeof(data), 1, pfile);
    rewind(pfile);

    return record;
}

data read_record_from_file_2(FILE *pfile, int index) {
    int offset = index * sizeof(data);
    fseek(pfile, offset, SEEK_SET);
    data record;
    fread(&record, sizeof(data), 1, pfile);
    rewind(pfile);

    return record;
}
