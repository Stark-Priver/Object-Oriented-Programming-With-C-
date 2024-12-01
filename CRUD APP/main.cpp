#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Product {
private:
    std::string name;     // Product name
    double price;         // Product price
    int quantity;         // Available quantity

public:
    // Constructor
    Product(const std::string &productName, double productPrice, int productQuantity)
            : name(productName), price(productPrice), quantity(productQuantity) {}

    // Getters and Setters
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setName(const std::string &newName) { name = newName; }
    void setPrice(double newPrice) { price = newPrice; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }

    // Method to display the product's details
    void display() const {
        std::cout << "Product: " << name << ", Price: $" << price << ", Quantity: " << quantity << std::endl;
    }
};

// Utility function to clear the input buffer
void clearInputBuffer() {
    std::cin.clear(); // Clears any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the rest of the input buffer
}

// Function to create a new product
void createProduct(std::vector<Product> &products) {
    std::string name;
    double price;
    int quantity;

    std::cout << "Enter product name: ";
    std::getline(std::cin, name);

    std::cout << "Enter product price: $";
    while (!(std::cin >> price)) {
        std::cout << "Invalid price. Please enter a valid number: $";
        clearInputBuffer();
    }
    clearInputBuffer();

    std::cout << "Enter product quantity: ";
    while (!(std::cin >> quantity)) {
        std::cout << "Invalid quantity. Please enter a valid number: ";
        clearInputBuffer();
    }
    clearInputBuffer();

    products.push_back(Product(name, price, quantity)); // Add the new product to the list
    std::cout << "Product added successfully!" << std::endl;
}

// Function to display all products
void displayAllProducts(const std::vector<Product> &products) {
    if (products.empty()) {
        std::cout << "No products available." << std::endl;
        return;
    }
    std::cout << "\n--- Product List ---\n";
    for (const auto &product : products) {
        product.display();
    }
}

// Function to modify a product's details
void modifyProduct(std::vector<Product> &products) {
    std::string name;
    std::cout << "Enter the product name to modify: ";
    std::getline(std::cin, name);

    for (auto &product : products) {
        if (product.getName() == name) {
            double newPrice;
            int newQuantity;

            std::cout << "Enter new price for " << name << ": $";
            while (!(std::cin >> newPrice)) {
                std::cout << "Invalid price. Please enter a valid number: $";
                clearInputBuffer();
            }
            clearInputBuffer();

            std::cout << "Enter new quantity for " << name << ": ";
            while (!(std::cin >> newQuantity)) {
                std::cout << "Invalid quantity. Please enter a valid number: ";
                clearInputBuffer();
            }
            clearInputBuffer();

            product.setPrice(newPrice);
            product.setQuantity(newQuantity);

            std::cout << "Product details updated." << std::endl;
            return;
        }
    }
    std::cout << "Product with name \"" << name << "\" not found." << std::endl;
}

// Function to delete a product
void deleteProduct(std::vector<Product> &products) {
    std::string name;
    std::cout << "Enter the product name to delete: ";
    std::getline(std::cin, name);

    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getName() == name) {
            products.erase(it);
            std::cout << "Product \"" << name << "\" deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Product with name \"" << name << "\" not found." << std::endl;
}

int main() {
    std::vector<Product> products; // List of products
    int choice;

    while (true) {
        std::cout << "\n=== Retail Shop Management ===\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. View All Products\n";
        std::cout << "3. Modify Product\n";
        std::cout << "4. Delete Product\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            clearInputBuffer();
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                createProduct(products); // Create a new product
                break;
            case 2:
                displayAllProducts(products); // Display all products
                break;
            case 3:
                modifyProduct(products); // Modify an existing product
                break;
            case 4:
                deleteProduct(products); // Delete a product
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
