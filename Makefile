CC = g++
EXEC = Battleship
LIBS = `sdl-config --cflags --libs` -lSDL -lSDLmain -lSDL_image -lSDL_ttf
FLAGS = -Wall

all:
	$(CC) src/main.cpp -o $(EXEC) $(LIBS) $(FLAGS)

clean:
	rm $(EXEC)