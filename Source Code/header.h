#include <stdio.h>
/*STRUCT DECLARATIONS*/

typedef struct BankAccount {
    char * name;
    int accountNum;
    int accountPin;
    float balance;
    struct BankAccount* next;
    struct BankAccount* prev;
} Account;

typedef struct LinkedList{
    Account* head;
    Account* tail;
    int size;
} List;

/*LIST.C FUNCTION PROTOTYPES*/

void addAccount(List* list, Account* toAdd);
void deleteAccount(List* list, int i);
int getSize(List* list);
Account* getAccount(List* list, int i);
Account* searchAccount(List* list, int account, int pin);
void readFile(List* list,char* fileName);
void writeFile(List* list, char* fileName);
void withdraw(Account* a, float amount);
void deposit(Account* a, float amount);

Account* newAccount();
List* newList();


/*IO.C FUNCTION PROTOTYPES*/
int inputAccountNum();
int inputNumberMaxValue(int max);
char* inputString();
int inputPin();

/*MAIN.C FUNCTION PROTOTYPES*/
void printMenu();
Account* login();
void displayAccounts();
void saveData();
void readData();

