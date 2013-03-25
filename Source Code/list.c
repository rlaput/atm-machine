#include "header.h"

void addAccount(List* list, Account a){
    Account * toAdd = &a;
    toAdd->prev = list->tail->prev;
    toAdd->next = list->tail;
    list->tail->prev->next = toAdd;
    list->tail->prev = toAdd;
    list->size++;
}

void deleteAccount(List* list, int i){
    Account * toDelete = &(getAccount(list,i));
    toDelete->next->prev = toDelete->prev;
    toDelete->prev->next = toDelete->next;
    free(toDelete);
    list->size--;
}

int getSize(List* list){
    return list->size;
}

Account getAccount(List* list, int i){
    Account * toGet = list->head;
    if(list->size == 0) return NULL;
    for(;i > 0;i--) toGet = toGet->next;
    return *toGet;
}

Account * searchAccount(List* list, int account, int pin){
    Account * toSearch = list->head->next;
    while(toSearch != tail){
        while(toSearch->accountNum != account && toSearch->accountPin != pin) toSearch = toSearch->next;
        return toSearch;
    }
    return NULL;
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



