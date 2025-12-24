CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJ = main.o lexer.o
TARGET = compiler

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c lexer.h token.h
	$(CC) $(CFLAGS) -c main.c

lexer.o: lexer.c lexer.h token.h
	$(CC) $(CFLAGS) -c lexer.c

clean:
	rm -f $(OBJ) $(TARGET)
