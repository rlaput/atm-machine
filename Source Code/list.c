#include "header.h"

void addAccount(List* list, Account a){

}

void deleteAccount(List* list, int i){

}

int getSize(List* list){

}

Account getAccount(List* list, int i){

}

Account * searchAccount(List* list, int account, int pin){

}

void readFile(List* list,char* fileName){

}

void writeFile(List* list, char* fileName){

}

void withdraw(Account* a, double amount){

}

void deposit(Account* a, double amount){

}

List * newList(){
    List* list = (List *) calloc(1,sizeof(List));
    list->head = newAccount();
    list->tail = newAccount();
    list->size = 0;
    list->head->next = list->tail;
    list->tail->prev = list->head;
    return list;
}

Account* newAccount(){
    Account* acc = (Account*) calloc(1,sizeof(Account));
    acc->name = (char*) calloc(80,sizeof(char));
    acc->accountNum = 0;
    acc->accountPin = 0;
    acc->balance = 0;
    acc->next = (Account*) calloc(1,sizeof(Account));
    acc->prev = (Account*) calloc(1,sizeof(Account));
    return acc;
}



