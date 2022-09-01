CC=gcc

СFLAGS=-Wall -Wextra -Werror -c

door_struct: dmanager_module.o
	$(CC) dmanager_module.o -o ../build/Quest_1

list_test: list_test.o list.o
	$(CC) list_test.o  list.o -o ../build/Quest_2


list.o: list.c 
	$(CC) $(СFLAGS) list.c 

list_test.o: list_test.c 
	$(CC) $(СFLAGS) list_test.c 

ddmanager_module.o: dmanager_module.c
	$(CC) $(СFLAGS) dmanager_module.c

clean:
	rm -f *.o

rebuild:
	make clean
	make 



