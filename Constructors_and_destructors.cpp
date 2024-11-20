#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    std::string grade;

public:
    // Constructor
    Student(const std::string &studentName, int studentAge, const std::string &studentGrade) 
        : name(studentName), age(studentAge), grade(studentGrade) {
        std::cout << "Student " << name << " enrolled in grade " << grade << " at age " << age << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Student " << name << " has graduated from grade " << grade << std::endl;
    }

    // Method to update grade
    void updateGrade(const std::string &newGrade) {
        grade = newGrade;
        std::cout << name << " has been promoted to grade " << grade << std::endl;
    }

    // Method to celebrate birthday
    void celebrateBirthday() {
        age++;
        std::cout << "Happy Birthday " << name << "! You are now " << age << " years old." << std::endl;
    }

    // Method to get student details
    void getDetails() const {
        std::cout << "Student Name: " << name << ", Age: " << age << ", Grade: " << grade << std::endl;
    }
};

int main() {
    // Creating a student object
    Student student("Alice", 14, "8th");

    // Performing some actions
    student.getDetails();
    student.celebrateBirthday();
    student.updateGrade("9th");

    // The destructor will be called automatically when the object goes out of scope
    return 0;
}
