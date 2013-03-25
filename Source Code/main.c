#include <stdio.h>
#include "header.h"

List list;
Account a, *acc;

int main(){
    int choice;
    list = *(newList());
    do{
        printMenu();
        choice = inputNumberMaxValue(5);
        switch(choice){
        case 1:
            a = *(newAccount());
            system("cls");
            printf("ADD AN ATM ACCOUNT\n");
            printf("\nEnter your Name: ");
            a.name = inputString();
            printf("\nEnter your Account Number (9 Digits): ");
            a.accountNum = inputAccountNum();
            printf("\nEnter your Account Pin (6 Digits): ");
            a.accountPin = inputPin();
            addAccount(&list,a);
            printf("\n\nAccount Successfully Added");
            getch();
            break;
        case 2:
            break;
        case 3:
            acc = login();
            if(acc == NULL){
                printf("Invalid Login Credentials");
            }
            break;
        case 4:
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
    printf("\t4. Delete an Account\n");
    printf("\t5. Exit\n\n");
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
    return searchAccount(&list,num,pin);
}
