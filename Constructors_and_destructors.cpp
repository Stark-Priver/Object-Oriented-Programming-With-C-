#include <iostream>
#include <cmath>

class Shape {
public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Shape() {
        std::cout << "Shape destructor called" << std::endl;
    }

    // Pure virtual functions for area, volume, and circumference
    virtual double area() const = 0;
    virtual double volume() const = 0;
    virtual double circumference() const = 0;
};

class Circle : public Shape {
public:
    // Parameterized constructor
    Circle(double radius) : radius(radius) {
        std::cout << "Circle constructor called" << std::endl;
    }

    // Destructor
    ~Circle() {
        std::cout << "Circle destructor called" << std::endl;
    }

    double area() const override {
        return M_PI * radius * radius;
    }

    double volume() const override {
        return 0; // Circle does not have volume
    }

    double circumference() const override {
        return 2 * M_PI * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    // Parameterized constructor
    Rectangle(double width, double height) : width(width), height(height) {
        std::cout << "Rectangle constructor called" << std::endl;
    }

    // Destructor
    ~Rectangle() {
        std::cout << "Rectangle destructor called" << std::endl;
    }

    double area() const override {
        return width * height;
    }

    double volume() const override {
        return 0; // Rectangle does not have volume
    }

    double circumference() const override {
        return 2 * (width + height);
    }

private:
    double width;
    double height;
};

class Sphere : public Shape {
public:
    // Parameterized constructor
    Sphere(double radius) : radius(radius) {
        std::cout << "Sphere constructor called" << std::endl;
    }

    // Destructor
    ~Sphere() {
        std::cout << "Sphere destructor called" << std::endl;
    }

    double area() const override {
        return 4 * M_PI * radius * radius;
    }

    double volume() const override {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }

    double circumference() const override {
        return 0; // Sphere does not have circumference
    }

private:
    double radius;
};

void displayMenu() {
    std::cout << "Shape Calculator" << std::endl;
    std::cout << "1. Circle" << std::endl;
    std::cout << "2. Rectangle" << std::endl;
    std::cout << "3. Sphere" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose a shape: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double radius;
                std::cout << "Enter radius of the circle: ";
                std::cin >> radius;
                Circle circle(radius);
                std::cout << "Circle Area: " << circle.area() << std::endl;
                std::cout << "Circle Circumference: " << circle.circumference() << std::endl;
                break;
            }
            case 2: {
                double width, height;
                std::cout << "Enter width and height of the rectangle: ";
                std::cin >> width >> height;
                Rectangle rectangle(width, height);
                std::cout << "Rectangle Area: " << rectangle.area() << std::endl;
                std::cout << "Rectangle Circumference: " << rectangle.circumference() << std::endl;
                break;
            }
            case 3: {
                double radius;
                std::cout << "Enter radius of the sphere: ";
                std::cin >> radius;
                Sphere sphere(radius);
                std::cout << "Sphere Area: " << sphere.area() << std::endl;
                std::cout << "Sphere Volume: " << sphere.volume() << std::endl;
                break;
            }
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}