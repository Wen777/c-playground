CC=clang
CFLAGS=-I.

#all: rational_number_main_D0565617.c rational_number_D0565617.c rational_number_D0565617.h
#	$(CC) -o exec rational_number_main_D0565617.c -o rational_number.out

all: string_functions.o string_functions_app.c
	$(CC) string_functions_app.c string_functions.o -o string_functions_app.out

string_functions.o: string_functions.h string_functions.c
	$(CC) -c string_functions.c

clean:
	rm string_functions_app.out string_functions.o
