#include <iostream>
#include <string>
#include <map>

using namespace std;

// Base User Class
class User {
protected:
    string username;
    string password;
    string role;

public:
    virtual void dashboard() = 0; // Pure virtual function for role-specific dashboards

    bool login(string uname, string pass) {
        return (uname == username && pass == password);
    }

    string getRole() {
        return role;
    }

    string getUsername() {
        return username;
    }
};

// Derived Classes for Specific Roles
class Staff : public User {
public:
    Staff(string uname, string pass) {
        username = uname;
        password = pass;
        role = "Staff";
    }

    void dashboard() override {
        cout << "\n--- Staff Dashboard ---\n";
        cout << "1. Update College Info\n2. Assist Students\n3. Logout\n";
    }
};

class Admin : public User {
public:
    Admin(string uname, string pass) {
        username = uname;
        password = pass;
        role = "Admin";
    }

    void dashboard() override {
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. Add Staff\n2. View All Users\n3. Logout\n";
    }

    void addStaff(map<string, User*>& userDatabase); // Declaration only

    void viewAllUsers(map<string, User*>& userDatabase) {
        cout << "\n--- All Users ---\n";
        for (auto& pair : userDatabase) {
            cout << "Username: " << pair.second->getUsername()
                 << ", Role: " << pair.second->getRole() << "\n";
        }
    }
};

// Complete Definition for Admin::addStaff
void Admin::addStaff(map<string, User*>& userDatabase) {
    string uname, pass;
    cout << "Enter staff username: ";
    cin >> uname;
    cout << "Enter staff password: ";
    cin >> pass;

    userDatabase[uname] = new Staff(uname, pass); // Staff is now fully defined
    cout << "Staff added successfully!\n";
}

class Student : public User {
public:
    Student(string uname, string pass) {
        username = uname;
        password = pass;
        role = "Student";
    }

    void dashboard() override {
        cout << "\n--- Student Dashboard ---\n";
        cout << "1. View Grades\n2. View Attendance\n3. View Course Info\n4. Logout\n";
    }

    void viewGrades() {
        cout << "Grades: A, B, A-\n";
    }

    void viewAttendance() {
        cout << "Attendance: 90%\n";
    }

    void viewCourses() {
        cout << "Courses: Mathematics, Science, History\n";
    }
};

class Accountant : public User {
public:
    Accountant(string uname, string pass) {
        username = uname;
        password = pass;
        role = "Accountant";
    }

    void dashboard() override {
        cout << "\n--- Accountant Dashboard ---\n";
        cout << "1. Manage Fee Payments\n2. View Financial Reports\n3. Logout\n";
    }
};

class Instructor : public User {
public:
    Instructor(string uname, string pass) {
        username = uname;
        password = pass;
        role = "Instructor";
    }

    void dashboard() override {
        cout << "\n--- Instructor Dashboard ---\n";
        cout << "1. Record Grades\n2. Manage Attendance\n3. Logout\n";
    }
};

// Global Map to Store User Data
map<string, User*> userDatabase;

// Initialize Users
void initializeUsers() {
    userDatabase["admin1"] = new Admin("admin1", "adminpass");
    userDatabase["student1"] = new Student("student1", "studentpass");
    userDatabase["staff1"] = new Staff("staff1", "staffpass");
    userDatabase["accountant1"] = new Accountant("accountant1", "accountantpass");
    userDatabase["instructor1"] = new Instructor("instructor1", "instructorpass");
}

// Authenticate User
User* authenticate(string uname, string pass) {
    if (userDatabase.find(uname) != userDatabase.end() && userDatabase[uname]->login(uname, pass)) {
        return userDatabase[uname];
    }
    return nullptr;
}

// Main Function
int main() {
    initializeUsers();

    string username, password;
    User* loggedInUser = nullptr;

    while (true) {
        cout << "\n=== College Management System ===\n";
        if (!loggedInUser) {
            // Login Prompt
            cout << "Login:\n";
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            loggedInUser = authenticate(username, password);
            if (loggedInUser) {
                cout << "Welcome, " << loggedInUser->getRole() << "!\n";
            } else {
                cout << "Invalid credentials. Please try again.\n";
            }
        } else {
            // Role-Specific Dashboard
            loggedInUser->dashboard();

            int choice;
            cin >> choice;

            if (loggedInUser->getRole() == "Admin") {
                Admin* admin = dynamic_cast<Admin*>(loggedInUser);
                if (choice == 1) {
                    admin->addStaff(userDatabase);
                } else if (choice == 2) {
                    admin->viewAllUsers(userDatabase);
                } else if (choice == 3) {
                    loggedInUser = nullptr;
                    cout << "You have logged out.\n";
                }
            } else if (loggedInUser->getRole() == "Student") {
                Student* student = dynamic_cast<Student*>(loggedInUser);
                if (choice == 1) {
                    student->viewGrades();
                } else if (choice == 2) {
                    student->viewAttendance();
                } else if (choice == 3) {
                    student->viewCourses();
                } else if (choice == 4) {
                    loggedInUser = nullptr;
                    cout << "You have logged out.\n";
                }
            } else {
                if (choice == 3) {
                    loggedInUser = nullptr;
                    cout << "You have logged out.\n";
                } else {
                    cout << "Option not yet implemented.\n";
                }
            }
        }
    }

    return 0;
}
