CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = ../../build/Quest_3
CLEAN_PATH = ../../build/Quest_5 ../../build/Quest_6 ../../build/Quest_4
CLEAN_PATH.o = ../data_libs/*.o ../data_module/*.o ../../build/*.o ../yet_another_decision_module/*.o ../../*.o
CLEAN_PATH.so = ../data_module/*.so ../../build/*.so
CLEAN_PATH.a = ../data_libs/*.a
SOURCES = ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c main_executable_module.c
MACRO_SOURCES = ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c main_executable_module.c
STATIC_SOURCES = ../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c main_executable_module.c
DYNAMIC_SOURCES = ../data_libs/data_io.c ../data_libs/data_stat.c ../yet_another_decision_module/decision.c main_executable_module.c
OBJECTS = $(SOURCES:.c=.o)
MACRO_OBJECTS = $(MACRO_SOURCES:.c=.o)
STATIC_OBJECTS = $(STATIC_SOURCES:.c=.o)
DYNAMIC_OBJECTS = $(DYNAMIC_SOURCES:.c=.o)

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

data_stat.a: data_stat.o ../data_libs/data_stat.c
	ar r data_stat.a data_stat.o

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c

data_process.so: data_process.o data_stat.o
	gcc -shared -o libdata_process.so data_process.o data_stat.o

data_io.o: ../data_libs/data_io_macro.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io_macro.c -o ./data_io.o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

build_with_macro: $(MACRO_OBJECTS) data_io.o
	$(CC) $(CFLAGS) $(MACRO_OBJECTS) ./data_io.o -o ../../build/Quest_4

build_with_static: $(STATIC_OBJECTS) data_stat.a
	$(CC) $($CFLAGS) $(STATIC_OBJECTS) data_stat.a -o ../../build/Quest_5

build_with_dynamic: $(DYNAMIC_OBJECTS) data_process.so
	$(CC) $($CFLAGS) -o ../../build/Quest_6 $(DYNAMIC_OBJECTS) -L ./ -ldata_process -Wl,-rpath,/Users/home_georgett/T09D15-0/src/main_executable_module

clean:
	rm -rf *.o *.a *.so $(TARGET) $(CLEAN_PATH) $(CLEAN_PATH.o) $(CLEAN_PATH.so) $(CLEAN_PATH.a)

rebuild:
	$(MAKE) clean
	$(MAKE) all
