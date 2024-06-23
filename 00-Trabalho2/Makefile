EXECUTAVEL = app
CFLAGS = -c -std=c++11

all: 	${EXECUTAVEL}

${EXECUTAVEL}: 	main.o Filme.o Ator.o Diretor.o
 				@g++ main.o Filme.o Ator.o Diretor.o -o ${EXECUTAVEL}

main.o: 		main.cpp Filme.cpp
 				@g++ ${CFLAGS} main.cpp

Filme.o: 		Filme.cpp Ator.cpp Diretor.cpp
 				@g++ ${CFLAGS} Filme.cpp

Ator.o: 		Ator.cpp
				@g++ ${CFLAGS} Ator.cpp

Diretor.o:		Diretor.cpp
				@g++ ${CFLAGS} Diretor.cpp

run: 			${EXECUTAVEL}
				@./${EXECUTAVEL}

clean:
				@rm-f main.o Filme.o Ator.o Diretor.o ${EXECUTAVEL}