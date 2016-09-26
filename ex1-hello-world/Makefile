# swhsiang swh@hsiang.io

COMMON_FLAGS += -Werror -Wextra
COMMON_FLAGS += -Wmissing-declarations
CFLAGS += ${COMMON_FLAGS}

*.o: Makefile
PROGRAMS_C=	hello

# suite.o: test_suite.c

config:
	curl -O https://raw.githubusercontent.com/silentbicycle/greatest/v1.2.1/greatest.h ;

build: greatest.h
	${CC} hello.c -o hello ${CFLAGS};

test:
	${CC} -o test_case ${CFLAGS} hello.c hello_test.c ;
	./test_case;

clean:
	rm -f ${PROGRAMS_C} *.o *.core greatest.h
