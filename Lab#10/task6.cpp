#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class InventoryItem{
    public:
        int itemID;
        char itemName[20];

    public:
        InventoryItem(int id, char name[20]):itemID(id){
            strncpy(itemName, name, 20);
        }
};

int main(){
    char s1[20] = "Calculator";
    char s2[20] = " ";
    InventoryItem obj1(1, s1);

    ofstream o;
    o.open("inventory.dat", ios::binary | ios::out);
    if(!o){
        cout << "Error while opening file" << endl;
    }

    o.write((char*)&obj1.itemID, sizeof(obj1.itemID));
    o.write(obj1.itemName, sizeof(obj1.itemName));

    o.close();

    InventoryItem obj2(0, s2);

    ifstream i;
    i.open("inventory.dat", ios::binary | ios::in);
    if(!i){
        cout << "Error while opening file" << endl;
    }

    i.read((char*)&obj2, sizeof(obj2));
    i.close();

    cout << "ID: " << obj2.itemID << endl;
    cout << "Name: " << obj2.itemName << endl;
}