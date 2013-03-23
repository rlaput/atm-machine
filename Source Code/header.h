/*STRUCT DECLARATIONS*/

typedef struct BankAccount {
    char * name;
    int accountNum;
    int accountPin;
    double balance;
    struct BankAccount* next;
    struct BankAccount* prev;
} Account;

typedef struct LinkedList{
    Account* head;
    Account* tail;
    int size;
} List;

/*LIST.C FUNCTION PROTOTYPES*/

void addAccount(List* list, Account a);
void deleteAccount(List* list, int i);
int getSize(List* list);
Account getAccount(List* list, int i);
Account * searchAccount(List* list, int account, int pin);
void readFile(List* list,char* fileName);
void writeFile(List* list, char* fileName);

Account* newAccount();
void withdraw(Account* a, double amount);
void deposit(Account* a, double amount);


/*IO.C FUNCTION PROTOTYPES*/
int inputNumberGetch();
int inputNumberMaxDigits(int digits);
int inputNumberMaxValue(int digits);
char* inputString();
int inputPin();

/*MAIN.C FUNCTION PROTOTYPES*/
void printMenu();
