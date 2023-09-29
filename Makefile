LDFLAGS = -lavcodec -lavformat

all: main.c
	gcc -o c-audio-player main.c $(LDFLAGS)
