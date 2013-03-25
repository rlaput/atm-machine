#include "header.h"

int inputAccountNum(){
    //numbers only 9 exact
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
    //no limit
}

int inputPin(){
    //numbers only, 6 digits exactly. asterisk only, backspace clear hjud, enter if 6 na
}

