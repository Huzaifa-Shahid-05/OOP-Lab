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

        Book(string t, float p, int s) {
	        this->title = t;
	        this->price = p;
	        this->stock = new int(s);
	    }

        Book(Book &obj) {
	        this->title = obj.title;
	        this->price = obj.price;
	        this->stock = new int(*obj.stock);
	    }

        ~Book () {
			delete stock;
			cout << "\nBook object: " << title << " destroyed.\n";
		}

        void updateBook(){
            cout << "Enter title: ";
            getline(cin, this->title);
            cout << "Enter price: ";
            cin >> this->price;
            cout << "Enter updated stock level: ";
            cin >> *(this->stock);
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
            if(quantity > *(this->stock)){
                cout << "This quantity is currently not available." << endl;
                cout << "Available copies: " << *(this->stock) << endl;
            }
            else{
                cout << "Purchase successfull." << endl;
                cout << "Price per book: " << price << endl;
                applyDiscount(quantity);
                *(this->stock) -= quantity;
            }
            if(*(this->stock) <= 5){
                cout << "Warning for low stock level" << endl;
            }
            cout << endl;
        }

        void Display(){
            cout << "Title: " << this->title << endl;
            cout << "Price: " << this->price << endl;
            cout << "Stock: " << *(this->stock) << endl;
            cout << endl;
        }
};

int main(){
    Book book1("Harry Potter", 100, 25);
    book1.Display();

    book1.purchaseBook(16);
    book1.Display();

    book1.purchaseBook(10);
    Book book2 = book1;
    
    cout << "Copied details: " << endl;
    book2.Display();
    
}