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

        Book(string t, float p, int s){
            title = t;
            price = p;
            stock = new int(s);
        }

        Book (Book &obj) {
			title = obj.title;
			price = obj.price;
			stock = new int (*obj.stock);
		}	
        
        ~Book () {
			delete stock;
			cout << "\nBook object: " << title << " destroyed.\n";
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

        void applyDiscount(int quantity){
            int sum = quantity*price;
            if(quantity > 10){
                sum *= 0.9;
            }
            else if(quantity > 5){
                sum *= 0.95;
            }
            cout << "The total after discount is: " << sum << endl;
        }

        void purchaseBook(int quantity){
            if(quantity > *stock){
                cout << "This quantity is currently not available." << endl;
                cout << "Available copies: " << *stock << endl;
            }
            else{
                cout << "Purchase successfull." << endl;
                cout << "Price per book: " << price << endl;
                applyDiscount(quantity);
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
    Book book1("Harry Potter", 100, 25);
    book1.Display();

    Book book2 (book1);
    cout << "\nCopy: \n";
    book2.Display();

    book1.updateBook();
    cout << "\nUpdating the original:\n";
    book1.Display();

    cout << "\nVerifying:\n";
    book2.Display();
    
}