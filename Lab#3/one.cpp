#include<iostream>
using namespace std;

class MarkerPens{
    public:
        string brand;
        string color;
        int inklevel;
        int refillability;
        

        void Refillability(){
            if(inklevel >= 10){
                refillability = 0;
            }
            else{
                refillability = 1;
            }
        }
        void write(){
            if(inklevel <= 0){
                cout << "Unable to write. Please refill your marker.\n" << endl;
            }
            else{
                inklevel--;
                cout << "You can proceed to write.\n" << endl;
            }
            Refillability();
        }
        void refill(){
            if(refillability == 1){
                inklevel = 10;
                cout << "The marker has been refilled.\n" << endl;
            }
            else{
                cout << "The marker cannot be refilled.\n" << endl;
            }
            Refillability();
        }      
};

void Input(MarkerPens &a) {  
    cout << "Enter the brand of marker: ";
    cin >> a.brand;
    cout << "Enter the color of marker: ";
    cin >> a.color;
    cout << "Enter the ink level of marker: ";
    cin >> a.inklevel;

    a.Refillability();
}

int main(){
    MarkerPens a;
    Input(a);

    cout << "1.Write\n2.Refill\n3.Exit\n" << endl;
    int choice;

    while(choice != 3){
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.write();
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