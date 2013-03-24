#include "header.h"

int inputAccountNum(){

}

int inputNumberMaxValue(int max){
    int input;
    scanf("%d" ,&input);
    while(input < 1 || input > max){
        printf("Input must be from 1 - %d. Input Again: ",max);
        scanf("%d" ,&input);
    }
    return input;
}

char* inputString(){

}

int inputPin(){

}

