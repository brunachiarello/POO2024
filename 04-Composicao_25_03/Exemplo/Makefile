# Makefile (Roland Teodorowitsch; 9 set. 2019)

EXECUTAVEL=app
CFLAGS=-c -std=c++11

all:		${EXECUTAVEL}

${EXECUTAVEL}:	main.o Data.o Produto.o
		@g++ main.o Data.o Produto.o -o ${EXECUTAVEL}

main.o:		main.cpp Data.hpp Produto.hpp
		@g++ ${CFLAGS} main.cpp

Produto.o:	Produto.cpp Produto.hpp Data.hpp
		@g++ ${CFLAGS} Produto.cpp

Data.o:		Data.cpp Data.hpp
		@g++ ${CFLAGS} Data.cpp

run:		${EXECUTAVEL}
		@./${EXECUTAVEL}

clean:
		@rm -f Produto.o Data.o main.o ${EXECUTAVEL}
