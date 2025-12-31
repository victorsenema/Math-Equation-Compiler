#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static void mathError(const char *errorMessage){
        if (errorMessage && errorMessage[0] != '\0')
                printf("%s", errorMessage);
}

float logFunction(float num, float base){
    if (num <= 0.0 || base <= 0.0 || base == 1.0){
        mathError("ERROR: Invalid input for log function");
        return NAN;
    }
    return log(num) / log(base);
}

float maxFunction(float num1, float num2){
        if(num1 >= num2) return num1;
        return num2;
}

float minFunction(float num1, float num2){
    if(num1 >= num2) return num2;
    return num1;
}

float sinFunction(float num){
    return sin(num);
}

float cosFunction(float num){
    return cos(num);
}

float absFunction(float num){
    return num < 0 ? -num: num;
}


