#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
        string title;
        float price;
        int* stock;
    public:
        Book(){
            title = "Unknown";
            price = 0.0;
            stock = new int(30);
        }

        void updateBook(){
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter updated stock level: ";
            cin >> *stock;
            cout << endl;
        }

        void purchaseBook(int quantity){
            if(quantity > *stock){
                cout << "This quantity is currently not available." << endl;
            }
            else{
                cout << "Purchase successfull." << endl;
                cout << "Price per book: " << price << endl;
                *stock -= quantity;
            }
            if(*stock <= 5){
                cout << "Warning for low stock level" << endl;
            }
            cout << endl;
        }

        void Display(){
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
            cout << "Stock: " << *stock << endl;
            cout << endl;
        }
};

int main(){
    Book book1;
    book1.updateBook();
    book1.Display();

    book1.purchaseBook(10);
    book1.Display();

    book1.purchaseBook(20);
    book1.Display();

}