#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Class representing a student
class Student {
private:
    std::string name; // Student's name
    int id;           // Student's ID

public:
    // Constructor: Initializes the Student object with a name and an ID
    Student(const std::string &studentName, int studentId)
            : name(studentName), id(studentId) {
        std::cout << "Constructor: Student " << name << " with ID " << id << " has been created." << std::endl;
    }

    // Destructor: Cleans up when the Student object is destroyed
    ~Student() {
        std::cout << "Destructor: Student " << name << " with ID " << id << " has been destroyed." << std::endl;
    }

    // Method to display the student's details
    void display() const {
        std::cout << "Student's name: " << name << ", ID: " << id << std::endl;
    }

    // Method to modify the student's name
    void setName(const std::string &newName) {
        name = newName;
    }

    // Method to modify the student's ID
    void setId(int newId) {
        id = newId;
    }

    // Method to get the student's ID
    int getId() const {
        return id;
    }
};

// Utility function to clear the input buffer
void clearInputBuffer() {
    std::cin.clear(); // Clears any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the rest of the input buffer
}

// Function to create a list of students
void createStudents(std::vector<Student> &students) {
    int n;
    std::cout << "Enter the number of students to add: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid number. Please enter a positive integer: ";
        clearInputBuffer();
    }
    clearInputBuffer(); // Clear the buffer after entering the number of students

    // Create and add students to the list
    for (int i = 0; i < n; ++i) {
        std::string name;
        int id;
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::getline(std::cin, name); // Input student's name
        std::cout << "Enter ID for student " << i + 1 << ": ";
        while (!(std::cin >> id)) {
            std::cout << "Invalid ID. Please enter an integer: ";
            clearInputBuffer(); // Handle invalid ID input
        }
        clearInputBuffer(); // Clear the buffer after entering the ID

        // Add the new student to the list
        students.push_back(Student(name, id));
    }
}

// Function to display all students
void displayAllStudents(const std::vector<Student> &students) {
    if (students.empty()) {
        std::cout << "No students to display." << std::endl;
        return;
    }

    std::cout << "\n--- All Students ---\n";
    for (const auto &student : students) {
        student.display();
    }
}

// Function to modify a student's details
void modifyStudent(std::vector<Student> &students) {
    int id;
    std::cout << "Enter ID of the student to modify: ";
    while (!(std::cin >> id)) {
        std::cout << "Invalid ID. Please enter an integer: ";
        clearInputBuffer(); // Handle invalid ID input
    }
    clearInputBuffer(); // Clear the buffer after entering the ID

    // Search for the student by ID and modify their details
    for (auto &student : students) {
        if (student.getId() == id) {
            std::string newName;
            int newId;

            std::cout << "Enter new name for student: ";
            std::getline(std::cin, newName); // Input new name

            std::cout << "Enter new ID for student: ";
            while (!(std::cin >> newId)) {
                std::cout << "Invalid ID. Please enter an integer: ";
                clearInputBuffer(); // Handle invalid ID input
            }
            clearInputBuffer(); // Clear the buffer after entering the ID

            student.setName(newName);
            student.setId(newId);

            std::cout << "Student details updated." << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found." << std::endl;
}

// Function to remove a student from the list
void removeStudent(std::vector<Student> &students) {
    int id;
    std::cout << "Enter ID of the student to remove: ";
    while (!(std::cin >> id)) {
        std::cout << "Invalid ID. Please enter an integer: ";
        clearInputBuffer(); // Handle invalid ID input
    }
    clearInputBuffer(); // Clear the buffer after entering the ID

    // Search for the student by ID and remove them
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it); // Remove the student from the list
            std::cout << "Student with ID " << id << " has been removed." << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found." << std::endl;
}

// Function to search for a student by ID
void searchStudentById(const std::vector<Student> &students) {
    int id;
    std::cout << "Enter ID of the student to search: ";
    while (!(std::cin >> id)) {
        std::cout << "Invalid ID. Please enter an integer: ";
        clearInputBuffer(); // Handle invalid ID input
    }
    clearInputBuffer(); // Clear the buffer after entering the ID

    // Search for the student by ID and display their details
    for (const auto &student : students) {
        if (student.getId() == id) {
            student.display();
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found." << std::endl;
}

// Main function: Entry point of the program
int main() {
    std::vector<Student> students; // Vector to hold the list of students

    // Create and manage students
    createStudents(students); // Create students
    displayAllStudents(students); // Display all students

    // Modify a student's details
    modifyStudent(students); // Modify details of a student
    displayAllStudents(students); // Display updated list of students

    // Search for a student by ID
    searchStudentById(students);

    // Remove a student from the list
    removeStudent(students);
    displayAllStudents(students); // Display all students after removal

    return 0;
}
