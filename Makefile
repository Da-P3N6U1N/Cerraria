CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
INLUDE_PATH = include
LIB_PATH = lib
LIBS = -lraylib -lgdi32 -lwinmm

TARGET = main.exe

all: $(TARGET)

$(TARGET):
	$(CC) -o $(TARGET) src/*.c -I$(INLUDE_PATH) -L$(LIB_PATH) $(CFLAGS) $(LIBS)

run: all
	@./$(TARGET)

clean:
	@del $(TARGET)