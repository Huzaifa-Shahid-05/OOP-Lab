#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class Fraction {
private:
    int numerator, denominator;

    void simplify() {
        int g = gcd(numerator, denominator);
        if (g < 0) g = -g;
        numerator /= g;
        denominator /= g;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            cout << "Error: Denominator is zero" << endl;
            exit(1);
        }
        numerator = num;
        denominator = denom;
        simplify();
    }

    Fraction operator+(const Fraction& f) const {
        int num = numerator * f.denominator + f.numerator * denominator;
        int denom = denominator * f.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& f) const {
        int num = numerator * f.denominator - f.numerator * denominator;
        int denom = denominator * f.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& f) const {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    Fraction operator/(const Fraction& f) const {
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction f1(2, 3), f2(3, 4);

    cout << "Initial values: " << endl;
    cout << "f1 = " << f1 << ", f2 = " << f2 << endl << endl;
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    return 0;
}
