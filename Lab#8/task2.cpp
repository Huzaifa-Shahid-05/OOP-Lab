#include<iostream>
using namespace std;

class Librarian;

class Book{
    private:
        string title;
        float price;
    public:
        Book(string t, float p): title(t), price(p){}

        friend class Librarian;
};

class Librarian{
    public:
        void Display(Book b){
            cout << "Title: " << b.title << endl;
            cout << "Price: " << b.price << endl << endl;
        }

        void discount(Book &b){
            b.price *= 0.9;
        }
};

int main(){
    Book b("Harry Potter", 5000.0);
    Librarian l;

    l.Display(b);
    l.discount(b);
    cout << "Updated Info: " << endl;
    l.Display(b);
}