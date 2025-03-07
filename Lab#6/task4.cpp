#include<iostream>
using namespace std;

class Account{
    public:
        int accountNumber;
        float balance;

        Account(int a, float b): accountNumber(a),balance(b){}

        void displayDetails(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

class SavingsAccount: public Account{
    public:
        float interestRate;

        SavingsAccount(int a, float b, float i): Account(a,b),interestRate(i){}

        void displayDetails(){
            Account::displayDetails();
            cout << "Interest Rate: " << interestRate << endl << endl;
        }
};

class CheckingAccount: public Account{
    public:
        float overdraftLimit;

        CheckingAccount(int a, float b, float i): Account(a,b),overdraftLimit(i){}

        void displayDetails(){
            Account::displayDetails();
            cout << "Over-draft Limit: " << overdraftLimit << endl << endl;
        }
};

int main(){
    SavingsAccount s(1286780,500000,5.2);
    CheckingAccount c(3971293,10000,8.9);

    s.displayDetails();
    c.displayDetails();
}