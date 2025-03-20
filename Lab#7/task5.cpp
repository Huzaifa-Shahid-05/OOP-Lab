#include<iostream>
using namespace std;

class Media{
    public:
        string title;
        string publicationDate;
        string uniqueID;
        string publisher;
        bool available;

        Media(string t, string p, string i, string pu, bool a):title(t),publicationDate(p),uniqueID(i),publisher(pu),available(a){}

        virtual void DisplayInfo(){
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl << endl;
        }

        void checkout(){
            if(available == 0){
                cout << "Item is not available for checkout." << endl; 
            }
            else{
                available = 0;
                cout << "Item checked out successfully." << endl;
            }
        }

        void returnItem(){
            available = 1;
            cout << "Item returned successfully." << endl;
        }
};

class Book: public Media{
    public:
        string author;
        string ISBN;
        int numOfPages;

        Book(string t, string p, string i, string pu, bool a, string x, string is, int n):Media(t,p,i,pu,a),author(x),ISBN(is),numOfPages(n) {}

        void DisplayInfo()override{
            cout << "----Book----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Author: " << author << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Number Of Pages: " << numOfPages << endl << endl;
        }
};

class DVD: public Media{
    public:
        string director;
        string duration;
        float ratings;

        DVD(string t, string p, string i, string pu, bool a, string x, string is, float n):Media(t,p,i,pu,a),director(x),duration(is),ratings(n) {}

        void DisplayInfo()override{
            cout << "----DVD----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << endl;
            cout << "Ratings: " << ratings << endl << endl;
        }
};

class CD: public Media{
    public:
        string artist;
        string genre;
        int numOfTracks;

        CD(string t, string p, string i, string pu, bool a, string x, string is, int n):Media(t,p,i,pu,a),artist(x),genre(is),numOfTracks(n) {}

        void DisplayInfo()override{
            cout << "----CD----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Artist: " << artist << endl;
            cout << "Genre: " << genre << endl;
            cout << "Number OF Tracks: " << numOfTracks << endl << endl;
        }
};

int main() {
    Book book("Harry Potter", "2021", "B001", "Bloomsburry", true, "J.K Rowling", "978-3-16-148410-0", 350);
    DVD dvd("Inception", "2010", "D001", "Warner Bros", true, "Christopher Nolan", "2h 28m", 8.8);
    CD cd("Thriller", "1982", "C001", "Epic Records", true, "Michael Jackson", "Pop", 9);

    book.DisplayInfo();
    dvd.DisplayInfo();
    cd.DisplayInfo();

    book.checkout();
    cout << endl;
    book.DisplayInfo();


    book.returnItem();
    cout << endl;
    book.DisplayInfo();

    return 0;
}