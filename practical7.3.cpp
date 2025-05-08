#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Item {
    char name[50];
    int quantity;
    float price;
};

void addItem(const char* filename) {
    Item item;

    cout << "Enter item name: ";
    cin.getline(item.name, 50);

    cout << "Enter quantity: ";
    cin >> item.quantity;

    cout << "Enter price: ";
    cin >> item.price;
    cin.ignore(); // flush newline

    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }


    outFile << item.name << "," << item.quantity << "," << item.price << "\n";
    outFile.close();

    cout << "Item added successfully.\n";
}

void viewInventory(const char* filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file for reading.\n";
        return;
    }

    cout << "\n--- Inventory ---\n";
    char line[128];
    while (inFile.getline(line, 128)) {
        char* token = strtok(line, ",");
        if (!token) continue;

        cout << "Name: " << token;

        token = strtok(nullptr, ",");
        if (token) cout << ", Quantity: " << token;

        token = strtok(nullptr, ",");
        if (token) cout << ", Price: " << token;

        cout << endl;
    }

    inFile.close();
}

void searchItem(const char* filename) {
    char searchName[50];
    cout << "Enter item name to search: ";
    cin.getline(searchName, 50);

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file.\n";
        return;
    }

    bool found = false;
    char line[128];
    while (inFile.getline(line, 128)) {
        char tempLine[128];
        strcpy(tempLine, line);

        char* token = strtok(line, ",");
        if (token && strcmp(token, searchName) == 0) {
            cout << "Item found: " << tempLine << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found.\n";
    }

    inFile.close();
}

int main() {
    const char* filename = "inventory.txt";
    int choice;

    do {
        cout << "\n--- Inventory Management ---\n";
        cout << "1. Add New Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addItem(filename); break;
            case 2: viewInventory(filename); break;
            case 3: searchItem(filename); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }

    } while (choice != 4);

    return 0;
}

