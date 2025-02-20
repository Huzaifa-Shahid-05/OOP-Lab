#include<iostream>
using namespace std;

class Patient{
    private:
        int ID;
        string name;
        int* testresults;

    public:
        Patient(int i, string s, int* results){
            ID = i;
            name = s;
            testresults = new int[5];
            for(int i = 0; i < 5; i ++){
                testresults[i] = results[i];
            }
        }
        Patient(const Patient& obj){
            ID = obj.ID;
            name = obj.name;
            testresults = new int[5];

            for(int i = 0; i < 5; i++){
                testresults[i] = obj.testresults[i];
            }
        }
        ~Patient(){
            delete[] testresults;
        }

        void Display(){
            cout << "ID: " << ID << endl;
            cout << "Name: " << name << endl;
            cout << "Test results: ";
            for(int i = 0; i < 5; i++){
                cout << testresults[i] << " ";
            }
            cout << endl << endl;
        
        }
};

int main(){
    int results[5] = {85,90,95,20,45};
    Patient p1(100,"Huzaifa",results);

    cout << "Original records: " << endl;
    p1.Display();

    Patient p2 = p1;
    cout << "Copied Records:" << endl;
    p2.Display();


}