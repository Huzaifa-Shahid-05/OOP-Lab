#include<iostream>
using namespace std;

class Laptop{
    public:
        string brand;
        int model;
        string processor, RAM, storage;
        bool isOn = false;
        
        void turnOn(){
            int choice;
            cout << "1.On\n2.Off" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                if(isOn){
                    cout << "Laptop is already on" << endl;
                }
                else{
                    cout << "Laptop turned on." << endl;
                    isOn = true;
                }
                cout << endl;
                break;

            case 2:
                if(!isOn){
                    cout << "Laptop is already off" << endl;
                }
                else{
                    cout << "Laptop turned off." << endl;
                    isOn = false;
                }
                cout << endl;
                break;
            
            default:
                cout << "Invalid choice.\n" << endl;
                break;
            }
        }

        void RunProgram(){
            string program;
            cout << "Enter program: ";
            cin >> program;

            if(isOn){
                cout << program << " is running\n" << endl;
            }
            else{
                cout << "Laptop is off." << endl;
            }
        }

        void CheckSpecs(){
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Processor: " << processor << endl;
            cout << "RAM: " << RAM << endl;
            cout << "Storage: " << storage << endl;
            cout << endl;
        }

        void InputSpecs(){
            cout << "Brand: ";
            cin >> brand;
            cout << "Model: ";
            cin >> model;
            std::cin.ignore();
            std::cout << "Enter processor: ";
            std::getline(std::cin, processor);
            cout << "RAM: ";
            cin >> RAM;
            cout << "Storage: ";
            cin >> storage;

            cout << endl;
        }
};

int main(){
    int choice;
    Laptop a;
    cout << "1.Input specification\n2.Check specification\n3.Turn On/Off\n4.Run a program\n5.Exit\n" << endl;
    while(choice != 5){
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.InputSpecs();
            break;
        case 2:
            a.CheckSpecs();
            break;
        case 3:
            a.turnOn();
            break;
        case 4:
            a.RunProgram();
            break;
        case 5:
            cout << "Exiting process." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
}

