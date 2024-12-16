#include <iostream>

using namespace std;

class Student {
private:
    string First_Name;
    string Last_Name;
    string Course_Name;
    int Reg_No;
    int Age;

    void setName(string fname) {
        First_Name = fname;
    }
    string getFist_Name() {
        return First_Name;
    }

public:


    void Display_Student() {
        cout << "My name is: " << First_Name + Last_Name << endl;
        cout << "My Registration Number is: " << Reg_No << endl;
        cout << "My age is: " << Age << endl;
        cout << "Am attending : "<<Course_Name << endl;
    };
    Student(string name1,string name2,string course,int reg_no,int age) {
        First_Name = name1;
        Last_Name = name2;
        Course_Name = course;
        Reg_No = reg_no;
        Age = age;


    }

};

int main() {
   
    return 0;
}