CC=clang
CFLAGS=-I.

#all: rational_number_main_D0565617.c rational_number_D0565617.c rational_number_D0565617.h
#	$(CC) -o exec rational_number_main_D0565617.c -o rational_number.out

all: rational_number_main_D0565617.c rational_number_D0565617.o
	$(CC) rational_number_main_D0565617.c rational_number_D0565617.o -o rational_number.out

rational_number_D0565617.o: rational_number_D0565617.c rational_number_D0565617.h
	$(CC) -c rational_number_D0565617.c

clean:
	rm rational_number.out rational_number_D0565617.o
