#include "header.h"

int inputAccountNum(){
    int input = 0;
    int i = 0, x=15;

    do{
        while(x < 0 || x > 9){
            x = getch() - '0';
            if((x < 0 || x > 9) && (x+'0') !=8)printf("\a");
            if((x + '0') == 8 && i != 0){
                printf("\b \b");
                input /= 10;
                i--;
                continue;
            }
        }

        printf("%d",x);
        input = (input*10) + x;
        i++;
        x = 15;
    }while(i<9);
    return input;

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
    char *input = (char*)calloc(80,sizeof(char));
    gets(input);
    return input;
}

int inputPin(){
    //numbers only, 6 digits exactly. asterisk only, backspace clear hjud, enter if 6 na
}

