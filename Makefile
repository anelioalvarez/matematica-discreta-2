TARGET = beta
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = $(wildcard *.c) $(wildcard */*.c)
HEADERS = $(wildcard *.h) $(wildcard */*.h)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJECTS)

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)

check: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET)
