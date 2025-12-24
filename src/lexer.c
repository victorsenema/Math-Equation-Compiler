#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "token.h"

int globalLineCursor = 0;

void lexicalError(const char *errorMessage){
    printf("%s", errorMessage);
    return;
}

static Token makeErrorToken(const char *msg) {
    Token t;
    lexicalError(msg);
    t.lexeme[0] = '\0';
    t.tokenType = TOKEN_ERROR;
    t.tokenValue = NONE;
    t.tablePosition = -1;
    t.variableValue = 0.0f;
    return t;
}

void initLexer(FILE *file){
    
    if (file == NULL) {
        perror("File is NULL");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        size_t lineSize = strlen(line);
        globalLineCursor = 0;
        getToken(line, lineSize);

        // TODO: process the line here
    }
}

bool isDigit(char c){
    return(c >= '0' && c <= '9');
}

void getToken(char *line, int lineSize){
    struct Token token;
    if(isDigit(line[globalLineCursor])||line[globalLineCursor] == '-'){
        token = getTOKEN_NUM(line, lineSize);
    }else{
        //error
        lexicalError("Unexpected character\n");
        return;
    }
    //ADD token to table
}

Token getTOKEN_NUM(char *line, int lineSize){
    struct Token numToken;
    bool hasDot = false;
    char tempString[256];

    int i = 0;

    if(line[globalLineCursor] == '-'){
        tempString[i] = '-';
        globalLineCursor++, i++;
        if (globalLineCursor >= lineSize || !isDigit(line[globalLineCursor])) {
            return makeErrorToken("A negative NUM needs a digit after the '-'\n");
        }
    }

    if(isDigit(line[globalLineCursor])){
        tempString[i] = line[globalLineCursor];
        i++, globalLineCursor++;
    }else{
        return makeErrorToken("NUM needs a digit\n");
    }

    while(globalLineCursor < lineSize  && i < (int)sizeof(tempString) - 1){
        char c = line[globalLineCursor];
        if(isDigit(c)){
            tempString[i] = c;
        }else if (c == '.' && !hasDot){
            hasDot = true;
            tempString[i] = '.';
        }else{
            break;
        }
        globalLineCursor++;
        i++;
    }
    tempString[i] = '\0';

    strncpy(numToken.lexeme, tempString, sizeof(numToken.lexeme) - 1);
    numToken.lexeme[sizeof(numToken.lexeme) - 1] = '\0';
    numToken.tokenType = TOKEN_NUM;
    numToken.tokenValue = NUM;
    numToken.variableValue = strtof(tempString, NULL);
    numToken.tablePosition = -1;//Por enquanto
    return numToken;
}