CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

LEX_DIR   = Lexer
PAR_DIR   = Parser
SYM_DIR   = SymbolTable
MATH_DIR  = MathFunction
TOK_DIR   = Token
MAIN_DIR  = Main

CFLAGS += -I$(LEX_DIR) -I$(PAR_DIR) -I$(SYM_DIR) -I$(MATH_DIR) -I$(TOK_DIR) -I$(MAIN_DIR)

OBJ = \
	$(MAIN_DIR)/main.o \
	$(LEX_DIR)/lexer.o \
	$(PAR_DIR)/parser.o \
	$(SYM_DIR)/symboltable.o \
	$(MATH_DIR)/mathFunction.o

TARGET = compiler.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(MAIN_DIR)/main.o: $(MAIN_DIR)/main.c \
	$(LEX_DIR)/lexer.h $(TOK_DIR)/token.h $(SYM_DIR)/symboltable.h $(PAR_DIR)/parser.h $(MATH_DIR)/mathFunction.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LEX_DIR)/lexer.o: $(LEX_DIR)/lexer.c \
	$(LEX_DIR)/lexer.h $(TOK_DIR)/token.h $(SYM_DIR)/symboltable.h
	$(CC) $(CFLAGS) -c $< -o $@

$(PAR_DIR)/parser.o: $(PAR_DIR)/parser.c \
	$(PAR_DIR)/parser.h $(LEX_DIR)/lexer.h $(TOK_DIR)/token.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SYM_DIR)/symboltable.o: $(SYM_DIR)/symboltable.c \
	$(SYM_DIR)/symboltable.h $(TOK_DIR)/token.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MATH_DIR)/mathFunction.o: $(MATH_DIR)/mathFunction.c \
	$(MATH_DIR)/mathFunction.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-del /Q "$(MAIN_DIR)\*.o" "$(LEX_DIR)\*.o" "$(PAR_DIR)\*.o" "$(SYM_DIR)\*.o" "$(MATH_DIR)\*.o" "$(TARGET)" 2>NUL
