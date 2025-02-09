#include<iostream>
using namespace std;

class Planner{
    public:
        string month[12][31] = {""};

        void Add(){
            int a,b;
            cout << "Enter the month: ";
            cin >> a;
            cout << "Enter the date: ";
            cin >> b;

            if(month[a - 1][b - 1] != ""){
                char ch;
                cout << "There is already a task planned for this date.Do you want to update this?\nEnter Y = Yes: ";
                cin >> ch;

                if(ch == 'Y'){
                    std::cin.ignore();
                    std::cout << "Enter task: ";
                    std::getline(std::cin, month[a-1][b-1]);
                    cout << endl;
                }
                else{
                    cout << "Exiting process." << endl;
                }
            }
            else{
                std::cin.ignore();
                std::cout << "Enter task: ";
                std::getline(std::cin, month[a-1][b-1]);
            } 
            cout << endl;      
        }
        void Remove(){
            int a,b;
            cout << "Enter the month: ";
            cin >> a;
            cout << "Enter the date: ";
            cin >> b;

            if(month[a - 1][b - 1] == ""){
                cout << "There is already no task planned for this date.\n" << endl;
            }
            else{
                month[a - 1][b - 1] = "";
                cout << "task removed successfully.\n" << endl;
            }
        }

        void Display(){
            for(int i = 0; i < 12; i++){
                cout << "Month " << i+1 << ": \n" << endl;
                for(int j = 0; j < 31; j++){
                    if(month[i][j] != ""){
                        cout << "Day" << j+1 << ": " << month[i][j] << endl;
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
};
int main(){
    int choice;
    Planner a;
    cout << "1.Add Task\n2.Remove Task\n3.Display task\n4.Exit" << endl;
    while(choice != 4){
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.Add();
            break;
        case 2:
            a.Remove();
            break;
        case 3:
            a.Display();
            break;
        case 4:
            cout << "Exiting process." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
}