#include <stdio.h>
#include "header.h"

List* list;
int i;

int main(){
    int choice;
    list = newList();
    do{
        Account *acc;
        printMenu();
        choice = inputNumberMaxValue(5);
        switch(choice){
        case 1:
            acc = newAccount();
            system("cls");
            printf("ADD AN ATM ACCOUNT\n");
            printf("\nEnter your Name: ");
            acc->name = inputString();
            printf("\nEnter your Account Number (9 Digits): ");
            acc->accountNum = inputAccountNum();
            printf("\nEnter your Account Pin (6 Digits): ");
            acc->accountPin = inputPin();
            addAccount(list,acc);
            printf("\n\nAccount Successfully Added");
            getch();
            break;
        case 2:
            system("cls");
            displayAccounts();
            getch();
            break;
        case 3:
            acc = login();
            if(acc == 0){
                printf("Invalid Login Credentials");
            }
            getch();
            break;
        case 4:
            system("cls");
            displayAccounts();
            printf("\n\nEnter Account Number to delete: --> ");
            i = inputNumberMaxValue(list->size);
            deleteAccount(list,i-1);
            printf("\nAccount Deleted.");
            getch();
            break;
        default:
            break;
        }
    }while(choice != 5);
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
    num=inputAccountNum();
    printf("\nEnter Pin Number --> ");
    pin=inputPin();
    return searchAccount(list,num,pin);
}

void displayAccounts(){
    printf("ACCOUNTS LIST\n");
    printf("\n%-5s%-15s%-20s%-10s\n", "No. ","Name","Account Num.","Balance");
    for(i=0;i<list->size;i++){
        Account* c = getAccount(list,i);
        printf("\n%-5d%-15s%-20d%-10.2f",i+1,c->name,c->accountNum,c->balance);
    }
}
