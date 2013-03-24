#include <stdio.h>
#include "header.h"

List list;

int main(){
    int choice;
    list = *(newList());
    do{
        printMenu();
        choice = inputNumberMaxValue(4);
        switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
    }while(choice != 4);
    return 0;
}

void printMenu(){
    system("cls");
    printf("WELCOME TO IMBA ATM MACHINE:\n\n");
    printf("Select an Option: \n\n");
    printf("\t1. Create new Account\n");
    printf("\t2. Display all Accounts\n");
    printf("\t3. Login in to Account\n");
    printf("\t4. Exit\n\n");
    printf("Enter Choice --> ");
}

Account* login(){
    int num,pin;
    system("cls");
    printf("LOGON TO YOUR ATM ACCOUNT:\n\n");
    printf("Enter Account Number --> ");
    scanf("%d",&num); //TO BE CHANGE TO num=inputAccountNum();
    printf("Enter Pin Number --> ");
    scanf("%d",&pin); //TO BE CHANGED TO pin=inputPin();
    return NULL;    //TO BE CHANGED TO return searchAccoun(list,num,pin);
}
