CC=clang
CFLAGS=-I.

#all: rational_number_main_D0565617.c rational_number_D0565617.c rational_number_D0565617.h
#	$(CC) -o exec rational_number_main_D0565617.c -o rational_number.out

all: hanoi_with_pegs_stack_array_main_D0565617.c hanoi_stack_array_D0565617.o
	$(CC) hanoi_with_pegs_stack_array_main_D0565617.c hanoi_stack_array_D0565617.o -o hanoi_with_pegs_stack_array.out

hanoi_stack_array_D0565617.o: hanoi_stack_array_D0565617.c hanoi_stack_array_D0565617.h
	$(CC) -c hanoi_stack_array_D0565617.c

clean:
	rm hanoi_with_pegs_stack_array.out hanoi_stack_array_D0565617.o
