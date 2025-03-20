#include<iostream>
using namespace std;

class Account{
    public:
        string AccountNumber;
        float balance;
        string AccountHolderName;
        string accountType;

        Account(string a, float b, string n, string t):AccountNumber(a), balance(b), AccountHolderName(n), accountType(t){}

        void deposit(float b){
            balance += b;
            cout << "$" << b << " deposited." << endl;
            cout << "Balance: $" << balance << endl;
        }

        virtual bool withdraw(float b){
            if(b > balance){
                cout << "Insufficient balance." << endl;
                return 0;
            }
            else{
                balance -= b;
                cout << "$" << b << " withdrawn" << endl;
                cout << "Balance: $" << balance << endl;
                return 1;
            }
        }

        virtual float calculateInterest(float b){
            cout << "Calculating interest" << endl;
            return 0;
        }

        virtual void printStatement(){
            cout << "Printing statement." << endl;
        }

        void getAccountInfo(){
            cout << "Account Number: " << AccountNumber << endl;
            cout << "Account Holder Name: " << AccountHolderName << endl;
            cout << "Balance: " << balance << endl;
            cout << "Account Type: " << accountType << endl;
        }
};

class SavingsAccount: public Account{
    public:
        float interestRate;
        float minBalance;

        SavingsAccount(string a, float b, string n, string t, float i, float m): Account(a,b,n,t),interestRate(i),minBalance(m){}

        float calculateInterest(float b) override{
            float interest = interestRate * (b/100);
            cout << "Interest for amount $" << b << "is $" << interest << endl;
            return interest;
        }

        bool withdraw(float b) override {
            if((balance - b) + calculateInterest(b) < minBalance){
                cout << "Insufficient balance. Balance would be below the min Balance" << endl;
                return 0;
            }
            else{
                balance -= b;
                cout << "$" << b << " withdrawn" << endl;
                cout << "Balance: $" << balance << endl;
                return 1;
            }
        }
};

class FixedDepositAccount : public Account{
    public:
        string maturityDate;
        float fixedInterestRate;

        FixedDepositAccount(string a, float b, string n, string t, string m): Account(a,b,n,t), maturityDate(m), fixedInterestRate(2.5) {}

        float calculateInterest(float b) override{
            float interest = fixedInterestRate * (b/100);
            cout << "Interest for amount $" << b << "is $" << interest << endl;
            return interest;
        }

        bool withdraw(float b) override {
            if(b + calculateInterest(b) < balance){
                cout << "Insufficient balance." << endl;
                return 0;
            }
            else{
                balance -= b;
                cout << "$" << b << " withdrawn" << endl;
                cout << "Balance: $" << balance << endl;
                return 1;
            }
        }
};

class CheckingAccount : public Account{
    public:
        float overDraftLimit;

        CheckingAccount(string a, float b, string n, string t, float o): Account(a,b,n,t),overDraftLimit(o){}

        float calculateInterest(float b) override{
            cout << "This account do not have interest" << endl;
            return 0;
        }

        bool withdraw(float b) override {
            if(b  < balance + overDraftLimit){
                cout << "Insufficient balance even after over draft limit." << endl;
                return 0;
            }
            else{
                balance -= b;
                cout << "$" << b << " withdrawn" << endl;
                cout << "Balance: $" << balance << endl;
                return 1;
            }
        }
};

int main() {
    SavingsAccount s("301479", 5000, "Huzaifa", "Savings", 2.0, 1000);
    FixedDepositAccount f("14807", 10000, "Ali", "Fixed Deposit", "01-01-2027");
    CheckingAccount c("134707", 3000, "Ismail", "Checking", 500);

    cout << "----Savings Account----" << endl;
    s.deposit(1000);
    s.calculateInterest(1000);
    s.withdraw(2000);
    cout << endl;
    s.getAccountInfo();
    cout << endl;


    cout << "----Fixed Deposit Account----" << endl;
    f.calculateInterest(5000);
    f.withdraw(3000);
    cout << endl;
    f.getAccountInfo();
    cout << endl;

    cout << "----Checking Account----" << endl;
    c.deposit(500);
    c.withdraw(3500);
    cout << endl;
    c.getAccountInfo();
    
    return 0;
}