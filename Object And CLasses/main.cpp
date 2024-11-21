#include <iostream>
#include <string>
#include <vector>

// Base class Student
class Student {
private:
    std::string name;
    int age;
    std::string course;

public:
    // Constructor
    Student(const std::string &n, int a, const std::string &c)
            : name(n), age(a), course(c) {}

    // Member function to display Student details
    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Course: " << course << std::endl;
    }

    // Getter for the course
    std::string getCourse() const {
        return course;
    }

    // Virtual function for demonstration of polymorphism
    virtual void getRole() const {
        std::cout << "Student role: Learner" << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Student() = default;
};

// Derived class GraduateStudent (inherits from Student)
class GraduateStudent : public Student {
private:
    std::string thesisTitle;
    std::string supervisor;

public:
    // Constructor
    GraduateStudent(const std::string &n, int a, const std::string &c, const std::string &t, const std::string &s)
            : Student(n, a, c), thesisTitle(t), supervisor(s) {}

    // Overriding getRole function
    void getRole() const override {
        std::cout << "Graduate Student role: Researcher" << std::endl;
        std::cout << "Thesis Title: " << thesisTitle << std::endl;
        std::cout << "Supervisor: " << supervisor << std::endl;
    }

    // Display detailed Graduate student info
    void displayGraduateInfo() const {
        displayInfo(); // Call base class method
        std::cout << "Thesis Title: " << thesisTitle << std::endl;
        std::cout << "Supervisor: " << supervisor << std::endl;
    }
};

// Person class for demonstrating abstraction
class Person {
public:
    virtual void intro() const = 0;  // Pure virtual function

    // Virtual destructor to allow derived class cleanup
    virtual ~Person() = default;
};

// Implementing Person in a new class PersonStudent
class PersonStudent : public Person, public Student {
public:
    // Constructor, passing necessary values to base classes
    PersonStudent(const std::string &n, int a, const std::string &c)
            : Student(n, a, c) {}

    // Overriding intro from Person
    void intro() const override {
        std::cout << "I am a student and my details are: " << std::endl;
        displayInfo(); // Calling Student's displayInfo
    }
};

// Function for demonstrating polymorphism
void displayRole(const Student &student) {
    student.getRole();
}

int main() {
    // Basic object creation and usage
    std::cout << "Basic Student Object:\n";
    Student student1("John Doe", 20, "Computer Science");
    student1.displayInfo();
    student1.getRole();

    // Inheritance demonstration
    std::cout << "\nGraduate Student Object:\n";
    GraduateStudent gradStudent1("Alice Smith", 24, "Biotechnology", "Gene Editing", "Dr. Allen");
    gradStudent1.displayGraduateInfo();
    gradStudent1.getRole();

    // Polymorphism demonstration
    std::cout << "\nPolymorphism Demonstration:\n";
    displayRole(student1);       // Calls Student's getRole
    displayRole(gradStudent1);   // Calls GraduateStudent's overridden getRole

    // Abstraction demonstration
    std::cout << "\nAbstraction with Person:\n";
    PersonStudent p_student("Jane Doe", 22, "Physics");
    p_student.intro();           // Calls Person's intro, which calls Student's displayInfo

    // Additional functionality: Using a vector to store objects
    std::vector<Student*> students;
    students.push_back(new Student("Tom Harris", 21, "Mathematics"));
    students.push_back(new GraduateStudent("Lisa Ray", 23, "Chemistry", "Organic Synthesis", "Dr. Brown"));

    // Displaying information of all students
    std::cout << "\nAll Students Info:\n";
    for (const auto& student : students) {
        student->displayInfo();
        student->getRole();
        std::cout << std::endl;
    }

    // Clean up dynamically allocated memory
    for (auto &student : students) {
        delete student;
    }

    return 0;
}