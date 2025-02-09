#include<iostream>
using namespace std;

class TeaMug{
    public:
        string brand;
        string color;
        int capacity = 10;
        int currentFillLevel;

        void sip(){
            if(currentFillLevel <= 0){
                cout << "Unable to sip. Please refill your mug.\n" << endl;
            }
            else{
                currentFillLevel--;
                cout << "You can proceed to sip.\n" << endl;
            }
        }
        void refill(){
            if(currentFillLevel < capacity){
                currentFillLevel = 10;
                cout << "The mug has been refilled.\n" << endl;
            }
            else{
                cout << "The mug cannot be refilled.\n" << endl;
            }
        }      
};

void Input(TeaMug &a) {  
    cout << "Enter the brand of mug: ";
    cin >> a.brand;
    cout << "Enter the color of mug: ";
    cin >> a.color;
    cout << "Enter the tea level of mug: ";
    cin >> a.currentFillLevel;

}

int main(){
    TeaMug a;
    Input(a);

    cout << "1.Sip\n2.Refill\n3.Exit\n" << endl;
    int choice;

    while(choice != 3){
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.sip();
            break;
        case 2:
            a.refill();
            break;
        case 3:
            cout << "Exiting process.\n";
            break;
        
        default:
            cout << "invalid choice.\n" << endl;
            break;
        }
    }
}