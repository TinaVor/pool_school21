CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: state_sort state_search

state_sort: state_sort.o 
	$(CC) state_sort.o -o ../build/state_sort

state_search: state_search.o
	$(CC) state_search.o -o ../build/state_search

state_sort.o: state_sort.c
	$(CC) $(СFLAGS) -c state_sort.c

state_search.o: state_search.c
	$(CC) $(СFLAGS) -c state_search.c

clean:
	rm -f *.o

rebuild:
	make clean
	make 
