# Makefile (Roland Teodorowitsch; 6 out. 2019)

EXECUTAVEL=app
CFLAGS=-c -std=c++11

all:		${EXECUTAVEL}

${EXECUTAVEL}:	main.o Banco.o Conta.o
		@g++ main.o Banco.o Conta.o -o ${EXECUTAVEL}

main.o:		main.cpp Conta.hpp Banco.hpp
		@g++ ${CFLAGS} main.cpp

Banco.o:	Banco.cpp Banco.hpp Conta.hpp
		@g++ ${CFLAGS} Banco.cpp

Conta.o:	Conta.cpp Conta.hpp
		@g++ ${CFLAGS} Conta.cpp

run:		${EXECUTAVEL}
		@./${EXECUTAVEL}

clean:
		@rm -f Conta.o Banco.o main.o ${EXECUTAVEL}