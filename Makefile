SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
TARGET=bfi

CC=clang
CFLAGS=-std=c89 -ansi -Wall -Wpedantic -Werror -Ofast

all: $(TARGET)
clean:
	rm -f $(OBJ) $(TARGET)
.PHONY: all clean

$(TARGET): $(OBJ)
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
