typedef struct Account {
    char * name;
    int accountNum;
    int accountPin;
    double balance;
    struct Account* next;
    struct Account* prev;
} Account;

