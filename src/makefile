CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = main.o controls.o myvector.o objects.o render.o textures.o
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = game

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) -o game $(OBJS) $(LIBS)

main.o: main.cpp myvector.hpp objects.hpp render.hpp
	$(CC) $(CFLAGS) -c main.cpp

controls.o: controls.cpp controls.hpp
	$(CC) $(CFLAGS) -c controls.cpp

myvector.o: myvector.cpp myvector.hpp
	$(CC) $(CFLAGS) -c myvector.cpp

objects.o: objects.cpp objects.hpp myvector.hpp textures.hpp
	$(CC) $(CFLAGS) -c objects.cpp

render.o: render.cpp render.hpp objects.hpp
	$(CC) $(CFLAGS) -c render.cpp

textures.o: textures.cpp textures.hpp objects.hpp
	$(CC) $(CFLAGS) -c textures.cpp

clean:
	\rm *.o $(EXEC)

