#include <iostream>
#include <vector>

// Class to represent a Person (base class for Teacher and Student)
class Person {
protected:
    std::string name;
    int age;
public:
    // Constructor to initialize name and age
    Person(std::string n, int a) : name(n), age(a) {}

    // Method to display person's details
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

// Class to represent a Student
class Student : public Person {
    std::string studentID;
public:
    // Constructor to initialize name, age, and student ID
    Student(std::string n, int a, std::string id) : Person(n, a), studentID(id) {}

    // Method to display student's details (overrides Person's display method)
    void display() const {
        Person::display(); // Call base class display
        std::cout << "Student ID: " << studentID << std::endl;
    }
};

// Class to represent a Teacher
class Teacher : public Person {
    std::string subject;
public:
    // Constructor to initialize name, age, and subject taught
    Teacher(std::string n, int a, std::string s) : Person(n, a), subject(s) {}

    // Method to display teacher's details (overrides Person's display method)
    void display() const {
        Person::display(); // Call base class display
        std::cout << "Subject: " << subject << std::endl;
    }
};

// Class to represent a School
class School {
    std::string schoolName;
    std::vector<Student> students; // List of students
    std::vector<Teacher> teachers; // List of teachers
public:
    // Constructor to initialize school name
    School(std::string name) : schoolName(name) {}

    // Method to add a student to the school
    void addStudent(const Student &student) {
        students.push_back(student);
    }

    // Method to add a teacher to the school
    void addTeacher(const Teacher &teacher) {
        teachers.push_back(teacher);
    }

    // Method to display school details along with teachers and students
    void display() const {
        std::cout << "School Name: " << schoolName << std::endl;

        std::cout << "\nTeachers:\n";
        for (const auto &teacher : teachers) {
            teacher.display();
        }

        std::cout << "\nStudents:\n";
        for (const auto &student : students) {
            student.display();
        }
    }
};

int main() {
    // Create a school
    School school("Green Valley High");

    // Create some students
    Student student1("Alice", 15, "S001");
    Student student2("Bob", 16, "S002");

    // Create some teachers
    Teacher teacher1("Dr. Smith", 40, "Mathematics");
    Teacher teacher2("Mrs. Johnson", 35, "History");

    // Add students to the school
    school.addStudent(student1);
    school.addStudent(student2);

    // Add teachers to the school
    school.addTeacher(teacher1);
    school.addTeacher(teacher2);

    // Display school details along with its teachers and students
    school.display();

    return 0;
}