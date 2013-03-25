#include <stdio.h>
#include "header.h"

List* list;
int i;

int main(){
    int choice,choice2;
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
                printf("\nInvalid Login Credentials");
            }
            else{
                printf("\n\nWELCOME TO YOUR ACCOUNT %s",acc->name);
                printf("\nCURRENT BALANCE %.2f",acc->balance);
                printf("\n\n\t1. Withdraw Money");
                printf("\n\t2. Deposit Money");
                printf("\n\t3. Back to Main Menu");
                printf("\nEnter Choice --> ");
                choice2 = inputNumberMaxValue(3);
                if(choice2 < 3){
                    float amount;
                    printf("\nEnter Amount: ");
                    scanf("%f",&amount);
                    if(choice2 == 1){
                        if(amount > acc->balance){
                            printf("\nNot Enough Funds.");
                            getch();
                            break;
                        }
                        withdraw(acc,amount);
                    }
                    else{
                        deposit(acc,amount);
                    }
                    printf("\n\nAction Successfull");
                    getch();

                }
            }
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
