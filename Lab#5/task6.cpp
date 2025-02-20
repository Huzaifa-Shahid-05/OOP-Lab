#include<iostream>
using namespace std;

class Movie{
    private:
        string title, director, duration;
    public:
        Movie(string t, string d, string s): title(t), director(d), duration(s){}
        Movie() : title(""), director(""), duration("") { }

        void Display(){
            cout << "Title: " << title << endl;
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << endl << endl;
        }
};

class CinemaHall{
    private:
        string name, address;
        int screens;
        Movie m[10];
        int numM;
    public:
        CinemaHall(string n, string a, int s) : name(n), address(a), screens(s), numM(0){}

        void AddMovie(string t, string d, string s){
            m[numM] = Movie(t,d,s);  
            numM++;
        }

        void Display() {
            cout << "Cinema Hall: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Number of screens: " << screens << endl << endl;
            cout << "Movies currently showing:" << endl;
            for (int i = 0; i < numM; i++) {
                m[i].Display();
            }
        }
};

int main(){
    CinemaHall c("Nuplex", "Askari IV", 5);
    c.AddMovie("Inception", "Christopher Nolan", "2h 28m");
    c.AddMovie("Interstellar", "Christopher Nolan", "2h 49m");
    
    c.Display();
}