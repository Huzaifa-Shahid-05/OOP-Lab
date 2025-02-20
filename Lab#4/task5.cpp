#include<iostream>
using namespace std;

class TourGuides{
    private:
        string name;
        string experiance;
        string specialization;
    public:
        TourGuides(string n, string e, string s):name(n),experiance(e),specialization(s){}

        void Display(){
            cout << "Name: " << name << endl;
            cout << "Experiance: " << experiance << endl;
            cout << "Specialization: " << specialization << endl << endl;
        }
};

class TravelAgency{
    private:
        string name;
        int numT;
        TourGuides** t1;
    public:
        TravelAgency(string n){
            numT = 0;
            name = n;
            t1 = new TourGuides*[10];
        }
        
        void AddGuide(string n, string e, string s){
            t1[numT] = new TourGuides(n,e,s);
            numT++;
        }
        void Display(){
            cout << "Travel Agency: " << name << endl << endl;
            cout << "Tour guide details: " << endl << endl;

            for(int i = 0; i < numT; i++){
                t1[i]->Display();
            }
        }
        ~TravelAgency(){
            for(int i = 0; i < numT; i++){
                delete[] t1[i];
            }
            delete[] t1;
        }
};

int main(){
    TravelAgency t("Hashmani Travels");
    t.AddGuide("Ali","5 years","Historical sites");
    t.AddGuide("Huzaifa", "7 months", "Natural Attractions");
    t.Display();
}