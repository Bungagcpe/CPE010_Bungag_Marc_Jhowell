#include <iostream>
#include <string>

class Groceries {
private:
    std::string type;
    std::string name;
    float price;
    int quantity;

public:
    // Constructor
    Groceries(std::string T = "", std::string N = "", double P = 0, int Q = 0) {
        type = T;
        name = N;
        price = P;
        quantity = Q;
    }

    // Destructor
    ~Groceries() {
        std::cout << name << " has been bagged." << std::endl;
    }

    // Copy Constructor
    Groceries(const Groceries &copyGroceries) {
        type = copyGroceries.type;
        name = copyGroceries.name;
        price = copyGroceries.price;
        quantity = copyGroceries.quantity;
    }

    // Copy Assignment Operator
    Groceries& operator=(const Groceries& copyGroceries) {
        if (this != &copyGroceries) {
            type = copyGroceries.type;
            name = copyGroceries.name;
            price = copyGroceries.price;
            quantity = copyGroceries.quantity;
        }
        return *this;
    }

    // Calculate total price
    double calculateSum() {
        return price * quantity;
    }

    // Display item details
    void ScannedItems() {
        std::cout << "Type: " << type << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: PHP " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total: PHP " << calculateSum() << std::endl;
        std::cout << std::endl;
    }
};

float TotalSum(Groceries* GroceryList[], int groceries) {
    float total = 0;

    for (int i = 0; i < groceries; i++) {
        if (GroceryList[i] != nullptr) {
            total += GroceryList[i]->calculateSum();
        }
    }
    return total;
}

int main() {
    Groceries* GroceryList[4];

    GroceryList[0] = new Groceries("Fruit", "Apple", 10, 7);
    GroceryList[1] = new Groceries("Fruit", "Banana", 10, 8);
    GroceryList[2] = new Groceries("Vegetable", "Broccoli", 60, 12);
    GroceryList[3] = new Groceries("Vegetable", "Lettuce", 50, 10);

    std::cout << "~~~~~Jenna's Grocery List~~~~~"<<std::endl;

    for (int i = 0; i < 4; i++) {
        GroceryList[i]->ScannedItems();
    }

    std::cout << "Total Cost: PHP " << TotalSum(GroceryList, 4) << std::endl;

    // Delete Lettuce
    delete GroceryList[3];
    GroceryList[3] = nullptr;
    std::cout << "After deleting Lettuce:" << std:: endl;
    std::cout << "Updated Total Cost: PHP " << TotalSum(GroceryList, 4) << std::endl;

    delete GroceryList[0];
    delete GroceryList[1];
    delete GroceryList[2];

    return 0;
}