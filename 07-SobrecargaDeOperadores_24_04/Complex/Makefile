# Makefile (Roland Teodorowitsch; 28 set. 2019)

EXECUTAVEL=app
CFLAGS=-c -std=c++11

all:		${EXECUTAVEL}

${EXECUTAVEL}:	main.o Complex.o
		@g++ main.o Complex.o -o ${EXECUTAVEL}

main.o:		main.cpp Complex.hpp
		@g++ ${CFLAGS} main.cpp

Complex.o:	Complex.cpp Complex.hpp
		@g++ ${CFLAGS} Complex.cpp

run:		${EXECUTAVEL}
		@./${EXECUTAVEL}

clean:
		@rm -f Complex.o main.o ${EXECUTAVEL}
