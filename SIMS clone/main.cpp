#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Structure to define a university-level course
struct Course {
    string courseCode;                  // Unique course code (e.g., "CS101")
    string courseName;                  // Full course name (e.g., "Introduction to Programming")
    vector<string> enrolledStudents;    // List of student usernames
    map<string, char> grades;           // Mapping of student IDs to their grades
    map<string, int> attendance;        // Mapping of student IDs to attendance percentage
};

// Global map to store courses
map<string, Course> courseDatabase;

// Base User Class: Defines shared properties and methods for all roles
class User {
protected:
    string username; // Login username
    string password; // Login password
    string role;     // User role (e.g., "Admin", "Student")

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

    virtual ~User() {} // Virtual destructor for cleanup
};

// Derived Classes for Specific Roles
class Admin : public User {
public:
    Admin(string uname, string pass) {
        username = uname;
        password = pass;
        role = "Admin";
    }

    void dashboard() override {
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. Add User\n2. Manage Courses\n3. View All Users\n4. Logout\n";
    }

    void addUser(map<string, User*>& userDatabase);
    void manageCourses();
    void viewAllUsers(const map<string, User*>& userDatabase);
};

class Student : public User {
public:
    Student(string uname, string pass) {
        username = uname;
        password = pass;
        role = "Student";
    }

    void dashboard() override {
        cout << "\n--- Student Dashboard ---\n";
        cout << "1. View Grades\n2. View Attendance\n3. Enroll in Course\n4. Logout\n";
    }

    void viewGrades();
    void viewAttendance();
    void enrollCourse();
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

    void recordGrades();
    void manageAttendance();
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

    void manageFeePayments();
    void viewFinancialReports();
};

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

    void updateCollegeInfo();
    void assistStudents();
};

// Admin Methods Implementation
void Admin::addUser(map<string, User*>& userDatabase) {
    string uname, pass, role;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pass;
    cout << "Enter role (Admin/Student/Instructor/Accountant/Staff): ";
    cin >> role;

    if (role == "Student") {
        userDatabase[uname] = new Student(uname, pass);
    } else if (role == "Instructor") {
        userDatabase[uname] = new Instructor(uname, pass);
    } else if (role == "Accountant") {
        userDatabase[uname] = new Accountant(uname, pass);
    } else if (role == "Staff") {
        userDatabase[uname] = new Staff(uname, pass);
    } else if (role == "Admin") {
        userDatabase[uname] = new Admin(uname, pass);
    } else {
        cout << "Invalid role! User not added.\n";
        return;
    }
    cout << "User added successfully!\n";
}

void Admin::manageCourses() {
    cout << "\n--- Manage Courses ---\n";
    cout << "1. Add Course\n2. View All Courses\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Course newCourse;
        cout << "Enter course code: ";
        cin >> newCourse.courseCode;
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, newCourse.courseName);
        courseDatabase[newCourse.courseCode] = newCourse;
        cout << "Course added successfully!\n";
    } else if (choice == 2) {
        cout << "\n--- All Courses ---\n";
        for (const auto& [code, course] : courseDatabase) {
            cout << "Course Code: " << code << ", Name: " << course.courseName << "\n";
        }
    } else {
        cout << "Invalid choice!\n";
    }
}

void Admin::viewAllUsers(const map<string, User*>& userDatabase) {
    cout << "\n--- All Users ---\n";
    for (const auto& [uname, user] : userDatabase) {
        cout << "Username: " << user->getUsername() << ", Role: " << user->getRole() << "\n";
    }
}

// Student Methods Implementation
void Student::viewGrades() {
    cout << "\n--- Your Grades ---\n";
    for (const auto& [code, course] : courseDatabase) {
        if (course.grades.find(username) != course.grades.end()) {
            cout << "Course: " << code << ", Grade: " << course.grades.at(username) << "\n";
        }
    }
}

void Student::viewAttendance() {
    cout << "\n--- Your Attendance ---\n";
    for (const auto& [code, course] : courseDatabase) {
        if (course.attendance.find(username) != course.attendance.end()) {
            cout << "Course: " << code << ", Attendance: " << course.attendance.at(username) << "%\n";
        }
    }
}

void Student::enrollCourse() {
    cout << "\n--- Enroll in Course ---\n";
    string courseCode;
    cout << "Enter course code: ";
    cin >> courseCode;

    if (courseDatabase.find(courseCode) != courseDatabase.end()) {
        courseDatabase[courseCode].enrolledStudents.push_back(username);
        cout << "Enrolled in course " << courseCode << " successfully!\n";
    } else {
        cout << "Invalid course code.\n";
    }
}

// Instructor Methods Implementation
void Instructor::recordGrades() {
    cout << "\n--- Record Grades ---\n";
    string courseCode, studentUsername;
    char grade;
    cout << "Enter course code: ";
    cin >> courseCode;
    cout << "Enter student username: ";
    cin >> studentUsername;
    cout << "Enter grade: ";
    cin >> grade;

    if (courseDatabase.find(courseCode) != courseDatabase.end()) {
        courseDatabase[courseCode].grades[studentUsername] = grade;
        cout << "Grade recorded successfully!\n";
    } else {
        cout << "Invalid course code.\n";
    }
}

void Instructor::manageAttendance() {
    cout << "\n--- Manage Attendance ---\n";
    string courseCode, studentUsername;
    int attendance;
    cout << "Enter course code: ";
    cin >> courseCode;
    cout << "Enter student username: ";
    cin >> studentUsername;
    cout << "Enter attendance percentage: ";
    cin >> attendance;

    if (courseDatabase.find(courseCode) != courseDatabase.end()) {
        courseDatabase[courseCode].attendance[studentUsername] = attendance;
        cout << "Attendance updated successfully!\n";
    } else {
        cout << "Invalid course code.\n";
    }
}

// Accountant Methods Implementation
void Accountant::manageFeePayments() {
    cout << "\n--- Manage Fee Payments ---\n";
    cout << "Feature not implemented yet.\n";
}

void Accountant::viewFinancialReports() {
    cout << "\n--- View Financial Reports ---\n";
    cout << "Feature not implemented yet.\n";
}

// Staff Methods Implementation
void Staff::updateCollegeInfo() {
    cout << "\n--- Update College Info ---\n";
    cout << "Feature not implemented yet.\n";
}

void Staff::assistStudents() {
    cout << "\n--- Assist Students ---\n";
    cout << "Feature not implemented yet.\n";
}

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
            loggedInUser->dashboard();

            int choice;
            cin >> choice;

            if (loggedInUser->getRole() == "Admin") {
                Admin* admin = dynamic_cast<Admin*>(loggedInUser);
                if (choice == 1) {
                    admin->addUser(userDatabase);
                } else if (choice == 2) {
                    admin->manageCourses();
                } else if (choice == 3) {
                    admin->viewAllUsers(userDatabase);
                } else if (choice == 4) {
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
                    student->enrollCourse();
                } else if (choice == 4) {
                    loggedInUser = nullptr;
                    cout << "You have logged out.\n";
                }
            } else if (loggedInUser->getRole() == "Instructor") {
                Instructor* instructor = dynamic_cast<Instructor*>(loggedInUser);
                if (choice == 1) {
                    instructor->recordGrades();
                } else if (choice == 2) {
                    instructor->manageAttendance();
                } else if (choice == 3) {
                    loggedInUser = nullptr;
                    cout << "You have logged out.\n";
                }
            } else if (loggedInUser->getRole() == "Accountant") {
                Accountant* accountant = dynamic_cast<Accountant*>(loggedInUser);
                if (choice == 1) {
                    accountant->manageFeePayments();
                } else if (choice == 2) {
                    accountant->viewFinancialReports();
                } else if (choice == 3) {
                    loggedInUser = nullptr;
                    cout << "You have logged out.\n";
                }
            } else if (loggedInUser->getRole() == "Staff") {
                Staff* staff = dynamic_cast<Staff*>(loggedInUser);
                if (choice == 1) {
                    staff->updateCollegeInfo();
                } else if (choice == 2) {
                    staff->assistStudents();
                } else if (choice == 3) {
                    loggedInUser = nullptr;
                    cout << "You have logged out.\n";
                }
            }
        }
    }

    return 0;
}
