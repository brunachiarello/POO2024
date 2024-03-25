ALL =			stringstream1 \
			stringstream2 \
			escrita \
			leitura \
			chamada

CFLAGS =		-std=c++11

all:			${ALL}

stringstream1:		stringstream1.cpp
			@g++ ${CFLAGS} -o stringstream1 stringstream1.cpp
			@./stringstream1 > stringstream1.output

stringstream2:		stringstream2.cpp
			@g++ ${CFLAGS} -o stringstream2 stringstream2.cpp

escrita:		escrita.cpp
			@g++ ${CFLAGS} -o escrita escrita.cpp

leitura:		leitura.cpp
			@g++ ${CFLAGS} -o leitura leitura.cpp

chamada:		chamada.cpp Aluno.cpp Aluno.hpp
			@g++ ${CFLAGS} -o chamada chamada.cpp Aluno.cpp
clean:
			@rm -f ${ALL} teste.txt chamada2.txt
