#include<iostream>
using namespace std;

class Media{
    public:
        string title;
        int publicationDate;
        string uniqueID;
        string publisher;
        bool available;

        Media(string t, int p, string i, string pu, bool a):title(t),publicationDate(p),uniqueID(i),publisher(pu),available(a){}

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

        Book(string t, int p, string i, string pu, bool a, string x, string is, int n):Media(t,p,i,pu,a),author(x),ISBN(is),numOfPages(n) {}

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

        DVD(string t, int p, string i, string pu, bool a, string x, string is, float n):Media(t,p,i,pu,a),director(x),duration(is),ratings(n) {}

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

        CD(string t, int p, string i, string pu, bool a, string x, string is, int n):Media(t,p,i,pu,a),artist(x),genre(is),numOfTracks(n) {}

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

class Library {
    private:
        Media ** collection;
        int numItems;
    public:
        Library() : collection(nullptr), numItems(0) {}
        void addMedia(Media *m) {
            Media** tempCollection = new Media*[numItems + 1];
            for(int i = 0; i < numItems; i++) {
                tempCollection[i] = collection[i];
            }
            tempCollection[numItems] = m;
            delete[] collection;
            numItems++;
            collection = tempCollection;
        }
        void searchMedia(string title) {
            cout << endl << "Searching media by title: " << title << endl;
            for(int i = 0; i < numItems; i++) {
                if(collection[i]->title == title) {
                    cout << "Media Item Found!" << endl;
                    collection[i]->DisplayInfo();
                    return;
                }
            }
            cout << "No media with matching title found!" << endl;
        }
        void searchMedia(int year) {
            cout << endl << "Searching all media published on year " << year << endl;
            bool found = false;
            for(int i = 0; i < numItems; i++) {
                if(collection[i]->publicationDate == year) {
                    found = true;
                    collection[i]->DisplayInfo();
                }
            }
            if(!found) {
                cout << "No Media with matching publication year found" << endl;
            }
        }
        ~Library() {
            if(numItems > 0) {
                delete[] collection;
            }
        }
};


int main() {
    Library l;
    Book book("Harry Potter", 2021, "B001", "Bloomsburry", true, "J.K Rowling", "978-3-16-148410-0", 350);
    DVD dvd("Inception", 2012, "D001", "Warner Bros", true, "Christopher Nolan", "2h 28m", 8.8);
    CD cd("Thriller", 1982, "C001", "Epic Records", true, "Michael Jackson", "Pop", 9);

    book.DisplayInfo();
    dvd.DisplayInfo();
    cd.DisplayInfo();

    book.checkout();
    cout << endl;
    book.DisplayInfo();


    book.returnItem();
    cout << endl;
    book.DisplayInfo();

    l.addMedia(&book);
    l.addMedia(&dvd);
    l.addMedia(&cd);

    l.searchMedia("Harry Potter");
    l.searchMedia(1982);
    

    return 0;
}