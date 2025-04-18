#include<iostream>
using namespace std;

class PaymentMethod{
    public:
        virtual bool processPayment(double amount) = 0;

        virtual ~PaymentMethod() {}
};

class CreditCard: public PaymentMethod{
    private:
        string cardNumber;
    public:
        CreditCard(string c):cardNumber(c){}

        bool processPayment(double amount)override{
            cout << "Card Number " << cardNumber << " charged $" << amount << endl;
            return 1;
        }
};

class DigitalWallet: public PaymentMethod{
    private:
        double balance;
    public:
        DigitalWallet(double b): balance(b) {}

        bool processPayment(double amount)override{
            if(balance > amount){
                balance -= amount;
                cout << "Payment of $" << amount <<" successfull"<< endl;
                return 1;
            }
            else{
                cout << "Insufficient balance" << endl;
                return 0;
            }
        }
};

int main(){
    CreditCard c("1234-5678-9");
    DigitalWallet d(100000);

    c.processPayment(50000);
    d.processPayment(50000);
    d.processPayment(60000);
}