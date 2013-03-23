#include <stdio.h>
#include "header.h"

int main(){
    int choice;
    do{
        printMenu();
        getch();
    }while(1);
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
