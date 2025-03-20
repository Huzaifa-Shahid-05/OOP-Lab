#include<iostream>
using namespace std;

class Currency{
    public:
        float amount;
        string currencyCode;
        string currencySymbol;
        float exchangeRate; // optional

        Currency(float a, string c, string s, float e): amount(a), currencyCode(c), currencySymbol(s), exchangeRate(e) {}

        virtual float convertToBase(){
            cout << "Converting this currency to base." << endl;
            return 0;
        }

        float convertToTarget(float e){ // passes new exchange rate
            cout << currencySymbol << amount << " is " << e*amount << " in target currency." << endl;
            return e*amount;
        } 

        virtual void displayCurrency(){
            cout << "Currency Code: " << currencyCode << endl;
            cout << "Currency Symbol: " << currencySymbol << endl;
            cout << "Amount: " << amount << endl;
            cout << "Exchange Rate: " << exchangeRate << endl;
        }
};

class Dollar: public Currency{
    public:
        Dollar(float a): Currency(a, "USD", "$", 280.5){}

        float convertToBase()override {
            cout << currencySymbol << amount << " is " << exchangeRate*amount << " in base currency" << endl;
            return exchangeRate*amount;
        }

        void displayCurrency(){
            cout << "----DOLLARS----" << endl;
            cout << "Currency Code: " << currencyCode << endl;
            cout << "Currency Symbol: " << currencySymbol << endl;
            cout << "Amount: " << amount << endl;
            cout << "Exchange Rate: " << exchangeRate << endl;
        }
};

class Euro: public Currency{
    public:
        Euro(float a): Currency(a, "EUR", "€", 150){}

        float convertToBase()override {
            cout << currencySymbol << amount << " is " << exchangeRate*amount << " in base currency" << endl;
            return exchangeRate*amount;
        }

        void displayCurrency()override{
            cout << "----Euro----" << endl;
            cout << "Currency Code: " << currencyCode << endl;
            cout << "Currency Symbol: " << currencySymbol << endl;
            cout << "Amount: " << amount << endl;
            cout << "Exchange Rate: " << exchangeRate << endl;
        }
};

class Ruppees: public Currency{
    public:
        Ruppees(float a): Currency(a, "Rs", "Rs", 1){}

        float convertToBase()override {
            cout << currencySymbol << amount << " is " << exchangeRate*amount << " in base currency" << endl;
            return exchangeRate*amount;
        }

        void displayCurrency()override{
            cout << "----Ruppees----" << endl;
            cout << "Currency Code: " << currencyCode << endl;
            cout << "Currency Symbol: " << currencySymbol << endl;
            cout << "Amount: " << amount << endl;
            cout << "Exchange Rate: " << exchangeRate << endl;
        }
};

int main(){
    Dollar d(100);
    Euro e(50);
    Ruppees r(10000);

    d.displayCurrency();
    d.convertToBase();
    cout << endl;

    e.displayCurrency();
    e.convertToBase();
    cout << endl;

    r.displayCurrency();
    r.convertToBase();
    cout << endl;
}