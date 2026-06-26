#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
};

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addItem(std::vector<Item> &inventory) {
    Item item;
    std::cout << "Enter item ID: ";
    std::cin >> item.id;
    clearInput();
    std::cout << "Enter item name: ";
    std::getline(std::cin, item.name);
    std::cout << "Enter item quantity: ";
    std::cin >> item.quantity;
    std::cout << "Enter item price: ";
    std::cin >> item.price;
    inventory.push_back(item);
    std::cout << "Item added successfully.\n";
}

void displayInventory(const std::vector<Item> &inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    std::cout << "\nCurrent Inventory:\n";
    std::cout << "ID\tName\tQuantity\tPrice\n";
    for (const auto &item : inventory) {
        std::cout << item.id << '\t' << item.name << '\t' << item.quantity << "\t" << item.price << '\n';
    }
}

int findItemIndex(const std::vector<Item> &inventory, int id) {
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void searchItem(const std::vector<Item> &inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    int id;
    std::cout << "Enter item ID to search: ";
    std::cin >> id;
    int index = findItemIndex(inventory, id);
    if (index == -1) {
        std::cout << "Item not found.\n";
        return;
    }
    const Item &item = inventory[index];
    std::cout << "Item found:\n";
    std::cout << "ID: " << item.id << "\n";
    std::cout << "Name: " << item.name << "\n";
    std::cout << "Quantity: " << item.quantity << "\n";
    std::cout << "Price: " << item.price << "\n";
}

void updateItem(std::vector<Item> &inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    int id;
    std::cout << "Enter item ID to update: ";
    std::cin >> id;
    int index = findItemIndex(inventory, id);
    if (index == -1) {
        std::cout << "Item not found.\n";
        return;
    }
    std::cout << "Enter new quantity: ";
    std::cin >> inventory[index].quantity;
    std::cout << "Enter new price: ";
    std::cin >> inventory[index].price;
    clearInput();
    std::cout << "Enter new name: ";
    std::getline(std::cin, inventory[index].name);
    std::cout << "Item updated successfully.\n";
}

void deleteItem(std::vector<Item> &inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    int id;
    std::cout << "Enter item ID to delete: ";
    std::cin >> id;
    int index = findItemIndex(inventory, id);
    if (index == -1) {
        std::cout << "Item not found.\n";
        return;
    }
    inventory.erase(inventory.begin() + index);
    std::cout << "Item deleted successfully.\n";
}

int main() {
    std::vector<Item> inventory;
    int choice = 0;

    while (true) {
        std::cout << "\nInventory Management System\n";
        std::cout << "1. Add item\n";
        std::cout << "2. Display inventory\n";
        std::cout << "3. Search item\n";
        std::cout << "4. Update item\n";
        std::cout << "5. Delete item\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addItem(inventory);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                searchItem(inventory);
                break;
            case 4:
                updateItem(inventory);
                break;
            case 5:
                deleteItem(inventory);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
