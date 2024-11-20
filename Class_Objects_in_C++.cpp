#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(std::string n, int a) : name(n), age(a) {}

    // Getter for name
    std::string getName() {
        return name;
    }

    // Getter for age
    int getAge() {
        return age;
    }

    // Setter for name
    void setName(std::string n) {
        name = n;
    }

    // Setter for age
    void setAge(int a) {
        age = a;
    }

    // Method to display person details
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating an object of Person class
    Person person1("John Doe", 30);

    // Displaying initial details
    person1.display();

    // Modifying details using setters
    person1.setName("Jane Doe");
    person1.setAge(25);

    // Displaying modified details
    person1.display();

    return 0;
}