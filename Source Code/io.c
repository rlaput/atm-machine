#include "header.h"

int inputNumberGetch(){

}

int inputAccountNum(){

}

int inputNumberMaxValue(int max){
    int input;
    scanf("%d" ,&input);
    while(input > max){
        printf("Cannot input above %d. Input Again: ",max);
        scanf("%d" ,&input);
    }
    return input;
}

char* inputString(){

}

int inputPin(){

}

