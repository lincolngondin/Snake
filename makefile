INCLUDEDIR = "./dependencies/include"
LIBSDIR = "./dependencies/lib"

./bin/Snake.exe: ./objs/main.o ./objs/Window.o ./objs/Snake.o 
	g++ ./objs/main.o ./objs/Window.o ./objs/Snake.o -I ${INCLUDEDIR} -L ${LIBSDIR} -lmingw32 -lSDL2main -lSDL2 -o ./bin/Snake.exe

./objs/Window.o: ./src/Window.cpp ./src/Window.h
	g++ -c ./src/Window.cpp -I ${INCLUDEDIR} -L ${LIBSDIR} -lmingw32 -lSDL2main -lSDL2 -o ./objs/Window.o

./objs/main.o: ./src/main.cpp
	g++ -c ./src/main.cpp -I ${INCLUDEDIR} -L ${LIBSDIR} -lmingw32 -lSDL2main -lSDL2 -o ./objs/main.o

./objs/Snake.o: ./src/Snake.cpp ./src/Snake.h
	g++ -c ./src/Snake.cpp -o ./objs/Snake.o

run:
	./bin/Snake.exe