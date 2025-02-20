#include<iostream>
using namespace std;

class Product{
    private:
        int id;
        string name;
        float price;

    public:
        Product() : id(0), name(""), price(0.0){}  
        Product(int i, string n, double p) : id(i), name(n), price(p){}

        string getName() { return name; }
        double getPrice() { 
            return price; 
        }
        
        void Display() {
            cout << "ID: " << id << endl;
            cout << "Name: " << name  << endl;
            cout << "Price: " << price << endl << endl;
        }
};

class Inventory{
    Product p[10];
    int numP;

    public:
        Inventory(){
            numP = 0;
        }

        void AddProducts(int i, string n, double pr){
            p[numP] = Product(i, n, pr);
            numP++;
        }

        void Sort(){
            for(int i = 0; i < numP; i++){
                for(int j = 0; j < numP - 1; j++){
                    if(p[j].getPrice() > p[j+1].getPrice()){
                        Product temp = p[j];
                        p[j] = p[j+1];
                        p[j+1] = temp;
                    }
                }
            }
        }

        void Search(string name){
            for(int i = 0; i < numP; i++){
                if(p[i].getName() == name){
                    cout << "Product found: \n";
                    p[i].Display();
                    return;
                }
            }
            cout << "Product not found." << endl << endl;
        }

        void DisplayAll() {
            cout << "\nInventory:\n";
            for (int i = 0; i < numP; i++) {
                p[i].Display();
            }
        }
};

int main() {
    Inventory store;

    store.AddProducts(101, "Laptop", 1200);
    store.AddProducts(103, "Apple", 2);
    store.AddProducts(104, "Headphones", 100);

    
    store.DisplayAll();
    store.Sort();
    cout << "Sorted: " << endl << endl;
    store.DisplayAll();
    store.Search("Laptop");
    store.Search("Banana");

    return 0;
}
