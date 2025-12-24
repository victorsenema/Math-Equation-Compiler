#include <stdio.h>
#include <string.h>
#include "token.h"

//ADD functionality that shows the user what the compiler did

int main() {
    char fileName[256];
    FILE *file;

    printf("Write the name of the .txt you want to compile:\n");
    scanf("%s", fileName);
    file = getFile(fileName);

    initLexer(file);

    fclose(file);
    return 0;
}