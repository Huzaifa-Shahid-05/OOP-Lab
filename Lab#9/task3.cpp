#include"book.h"
#include<iostream>
using namespace std;

int main(){
    Library l;

    Book* b1 = new Book("Harry Potter", "J.K Rowling", "123456");
    Book* b2 = new Book("The Hobbit", "Robert C. Martin", "789101");
    Book* b3 = new Book("Matilda", "Charlie Roberts", "1071422");

    l.add(b1);
    l.add(b2);
    l.add(b3);
    cout << endl;

    l.displayAllBooks();

    l.remove("The Hobbit");

    cout << endl << "After removing:" << endl;
    l.displayAllBooks();
}