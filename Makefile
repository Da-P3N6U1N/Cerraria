CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Iinclude
LDFLAGS = -Llib -lraylib
RLIBS = -lGL -lm -lpthread -ldl

TARGET = bin/main

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS) | bin
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(RLIBS)

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

bin:
	mkdir -p bin

run: clean all
	./$(TARGET)

clean:
	rm -rf obj bin
