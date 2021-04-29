CC=g++
TARGET=g
SOURCES=Game.cpp \
		Screen.cpp \
    main.cpp \

LDFLAGS=-lncursesw

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET)
