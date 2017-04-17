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

image_mirror.o: image_mirror.c
	clang -c image_mirror.c -o image_mirror.o

image_mirror: image_mirror.o
	clang image_mirror.o -o image_mirror
	./image_mirror red_dragon.bmp red_dragon_changed.bmp
	open red_dragon.bmp
	open red_dragon_changed.bmp
clean-image_mirror:
	-rm -f image_mirror.o
	-rm -f image_mirror

# image_flip
image_flip.o: image_flip.c
	clang -c image_flip.c -o image_flip.o

image_flip: image_flip.o
	clang image_flip.o -o image_flip 
	./image_flip red_dragon.bmp red_dragon_flip.bmp
	open red_dragon.bmp
	open red_dragon_flip.bmp
clean-image_flip:
	-rm -f image_flip.o
	-rm -f image_flip

# image_reduce
image_reduce.o: image_reduce.c
	clang -c image_reduce.c -o image_reduce.o

image_reduce: image_reduce.o
	clang image_reduce.o -o image_reduce 
	./image_reduce red_dragon.bmp red_dragon_reduce.bmp
	open red_dragon.bmp
	open red_dragon_reduce.bmp
clean-image_reduce:
	-rm -f image_reduce.o
	-rm -f image_reduce
