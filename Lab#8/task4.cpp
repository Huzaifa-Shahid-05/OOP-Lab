#include <iostream>
using namespace std;

class Currency {
private:
    float amount;

public:
    Currency(float a = 0) : amount(a) {}

    Currency operator-() const {
        return Currency(-amount);
    }

    Currency operator+(const Currency& other) const {
        return Currency(amount + other.amount);
    }

    Currency operator-(const Currency& other) const {
        return Currency(amount - other.amount);
    }

    Currency& operator+=(const Currency& other) {
        amount += other.amount;
        return *this;
    }

    Currency& operator-=(const Currency& other) {
        amount -= other.amount;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Currency& c) {
        cout << c.amount;
        return out;
    }
};

int main() {
    Currency c1(1500), c2(500), c3;

    cout << "Initial values:\n";
    cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

    c3 = c1 + c2;
    cout << "\nc1 + c2: " << c3 << endl;

    c3 = c1 - c2;
    cout << "c1 - c2: " << c3 << endl;

    c1 += c2;
    cout << "c1 += c2: " << c1 << endl;

    c1 -= c2;
    cout << "c1 -= c2: " << c1 << endl;

    c3 = -c1;
    cout << "-c1: " << c3 << endl;

    return 0;
}
