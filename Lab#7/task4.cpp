#include<iostream>
using namespace std;

class Person{
    public:
        string name;
        string id;
        string address;
        string phoneNumber;
        string email;

        Person(string s, string i, string a, string p, string e): name(s),id(i),address(a),phoneNumber(p),email(e) {}
        Person(){}

        virtual void displayInfo(){
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
        }

        void updateInfo(string a, string p, string e){
            address = e;
            phoneNumber = p;
            email = e;
        }
};

class Student: public Person{
    public:
        int coursesEnrolled;
        float GPA;
        string enrollmentYear;

        Student(string s, string i, string a, string p, string e, int c, float g, string b): Person(s,i,a,p,e),coursesEnrolled(c),GPA(g),enrollmentYear(b) {}
        Student(){}  

        void displayInfo()override{
            cout << "\n----Student----" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
            cout << "Courses Enrolled: " << coursesEnrolled << endl;
            cout << "GPA: " << GPA << endl;
            cout << "Enrollment Year: " << enrollmentYear << endl;
        }
};

class Professor: public Person{
    public:
        string department;
        string courseTaught;
        float salary;

        Professor(string s, string i, string a, string p, string e, string d, string c, float s1): Person(s,i,a,p,e),department(d),courseTaught(c),salary(s1) {}

        void displayInfo()override{
            cout << "\n----Professor----" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
            cout << "Department: " << department << endl;
            cout << "Course Taught: " << courseTaught << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Staff: public Person{
    public:
        string department;
        string Position;
        float salary;

        Staff(string s, string i, string a, string p, string e, string d, string c, float s1): Person(s,i,a,p,e),department(d),Position(c),salary(s1) {}

        void displayInfo()override{
            cout << "\n----Staff----" << endl;
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
            cout << "Department: " << department << endl;
            cout << "Position: " << Position << endl;
            cout << "Salary: " << salary << endl << endl;
        }
};

class Course{
    public:
        string CourseId;
        string CourseName;
        int credits;
        string Instructor;
        Student students[100];
        int numStudents;

        Course(string i, string n, int c, string in): CourseId(i), CourseName(n), credits(c), Instructor(in),numStudents(0){}

        void RegiterStudent(Student s){
            students[numStudents] = s;
            cout << "Student Registered Successfully." << endl;
        }

        void calculateGrade(Student s){
            if(s.GPA >= 4){
                cout << "Grade: A+" << endl;
            }
            else if(s.GPA >= 3.67){
                cout << "Grade: A" << endl;
            }
            else if(s.GPA >= 3.33){
                cout << "Grade: B" << endl;
            }
            else{
                cout << "Grade: C" << endl;
            }
        }
        
};

int main() {
    
    Student s1("Huzaifa", "0860", "Karachi", "03214567890", "k240860@nu.edu.pk", 5, 3.85, "2025");
    Professor p1("Sir Talha", "P202", "Karachi", "03331234567", "talha.shahid@gmail.com", "Computer Science", "OOP-Lab", 250000);
    Staff staff1("Imran", "ST303", "Karachi", "03001234567", "imran@email.com", "Administration", "HR Manager", 150000);
    Course c1("CS101", "OOP-Lab", 3, "Sir Talha");
    
   
    c1.RegiterStudent(s1);
    s1.displayInfo();
    p1.displayInfo();
    staff1.displayInfo();
    cout << "Student: " << s1.name << " has been registered in " << c1.CourseName << endl;
    c1.calculateGrade(s1);

    return 0;
}
