#include<iostream>
using namespace std;

class GroceryStore{
    public:
        string items[100];
        int prices[100];
        int max = 0;
    
        void Add(){
            cout << "Name of item: ";
            cin >> items[max];
            cout << "Price of item: ";
            cin >> prices[max];
    
            max++;
            cout << endl;
        }
        void update(){
            string name;
            bool found = false;
            cout << "Enter the name of item to update: ";
            cin >> name;
    
            for(int i = 0; i < max; i++){
                if(items[i] ==  name){
                    found = true;
                    cout << "Enter new price: ";
                    cin >> prices[i];
                    break;
                }
            }
            if(!found){
                cout << "Item not found." << endl;
            }
            cout << endl;
        }
        void viewInventory(){
            for(int i = 0; i < max; i++){
                cout << items[i] << "  " << prices[i] << endl;
            }
            cout << endl;
        }
        void receipt(){
            int num;
            cout << "Enter the number of different items to purchase: ";
            cin >> num;
            string name;
            int quantity;
            int sum = 0;
            bool found = false;
    
            for(int i = 0; i < num; i++){
                cout << "Enter the name of item" << i+1 << ": ";
                cin >> name;
    
                for(int j = 0; j < max; j++){
                    if(items[j] == name){
                        found = true;
                        cout << "Enter the quantity: ";
                        cin >> quantity;
    
                        sum += prices[j] * quantity;
                        break;
                    }
                }
                if(!found){
                    cout << "Item not found." << endl;
                }
            }
            cout << "The receipt of " << sum << "rs has been generated.\n" << endl;
        }
};    

int main(){
    GroceryStore a;

    cout << "1.Add item\n2.Update item\n3.View inventory\n4.Generate a receipt\n5.Exit\n" << endl;
    int choice = 0;
    while (choice != 5)
    {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.Add();
            break;
        case 2:
            a.update();
            break;
        case 3:
            a.viewInventory();
            break;
        case 4:
            a.receipt();
            break;
        case 5:
            cout << "Exiting process" << endl;
            break;
        
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    
}