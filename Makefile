CC=cc
CFLAGS=-I /usr/local/Cellar/sdl2/2.0.5/include/SDL2/ -I /usr/local/Cellar/sdl2_image/2.0.1_2/include/SDL2/
LIBS = -L /usr/local/Cellar/sdl2/2.0.5/lib/ -L /usr/local/Cellar/sdl2_image/2.0.1_2/lib/ -lSDL2_image -lSDL2

SOURCES = rally.c truck.c background.c util.c obstacles.c gametimer.c

rally:
	$(CC) $(CFLAGS) $(LIBS) $(SOURCES) -o rally
