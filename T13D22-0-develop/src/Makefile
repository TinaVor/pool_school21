CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: cipher

cipher: cipher.o
	$(CC) cipher.o -o ../build/cipher


cipher.o: cipher.c
	$(CC) $(СFLAGS) -c cipher.c

logger.o: logger.c
	$(CC) $(СFLAGS) -c -DLOG logger.c

loggin_cipher: cipher.o logger.o
	$(CC) cipher.o logger.o -o ../build/log

clean:
	rm -f *.o

rebuild:
	make clean
	make 
