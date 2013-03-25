#include "header.h"

void addAccount(List* list, Account* toAdd){
    toAdd->prev = list->tail->prev;
    toAdd->next = list->tail;
    list->tail->prev->next = toAdd;
    list->tail->prev = toAdd;
    list->size++;
}

void deleteAccount(List* list, int i){
    Account* toDelete = getAccount(list,i);
    toDelete->next->prev = toDelete->prev;
    toDelete->prev->next = toDelete->next;
    free(toDelete);
    list->size--;
}

int getSize(List* list){
    return list->size;
}

Account* getAccount(List* list, int i){
    Account* toGet = list->head;
    if(list->size == 0) return;
    for(;i >= 0;i--) {
        toGet = toGet->next;
    }
    return toGet;
}

Account* searchAccount(List* list, int account, int pin){
    Account* toSearch = list->head->next;
    while(toSearch != list->tail){
        if(toSearch->accountNum == account && toSearch->accountPin == pin){
            return toSearch;
        }
        toSearch = toSearch->next;
    }
    return 0;
}

void readFile(List* list,char* fileName){
    FILE* ifp = fopen(fileName, "r");
    Account* a = newAccount();
    while(!feof(ifp)){
        if(fscanf(ifp, "%s %d %d %f", a->name, &a->accountNum, &a->accountPin, &a->balance) != 4)
            break;
        addAccount(list, a);
    }
    fclose(ifp);
}

void writeFile(List* list, char* fileName){
    FILE* ofp = fopen(fileName, "w");
    Account* a = list->head->next;
    while(a != list->tail){
        fprintf(ofp, "%s %d %d %f\n", a->name, a-> accountNum, a->accountPin, a->balance);
    }
    fclose(ofp);
}

void withdraw(Account* a, float amount){
    a->balance -= amount;
}

void deposit(Account* a, float amount){
    a->balance += amount;
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



