CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = main.o controls.o myvector.o objects.o render.o textures.o
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = game

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) -o game $(OBJS) $(LIBS)

main.o: main.cpp myvector.hpp objects.hpp render.hpp
	$(CC) $(CFLAGS) main.cpp

controls.o: controls.cpp controls.hpp
	$(CC) $(CFLAGS) controls.cpp

myvector.o: myvector.cpp myvector.hpp
	$(CC) $(CFLAGS) myvector.cpp

objects.o: objects.cpp objects.hpp myvector.hpp textures.hpp
	$(CC) $(CFLAGS) objects.cpp

render.o: render.cpp render.hpp objects.hpp
	$(CC) $(CFLAGS) render.cpp

textures.o: textures.cpp textures.hpp objects.hpp
	$(CC) $(CFLAGS) textures.cpp

clean:
	\rm *.o $(EXEC)

