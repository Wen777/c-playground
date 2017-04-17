linklist.o: linklist.c
	clang -c linklist.c -o linklist.o

linklist: linklist.o
	clang linklist.o -o linklist
	./linklist
clean-linklist:
	-rm -f linklist.o
	-rm -f linklist

queue.o: queue.c
	clang -c queue.c -o queue.o

queue: queue.o
	clang queue.o -o queue
	./queue
clean-queue:
	-rm -f queue.o
	-rm -f queue