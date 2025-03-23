/*Subject code : CSEB3213 Data Structures & Algorithms
 Section : 01B
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : 3 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct meal {
    int id;
    string name;
    float price;
};


int menu();
void newMenu(vector<meal>& Record);
void displayMenu(const vector<meal>& Record);

int main() {
    vector<meal> Record {{1001, "Greek Lamb", 20.80}, {1002, "Chicken Pasta", 12.90}, {1003, "Tomyam Kung", 22.50}};
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                newMenu(Record);
                break;
            case 2:
                displayMenu(Record);
                break;
            case 3:
                cout << "Update menu function not implemented yet.\n";
                break;
            case 4:
                cout << "Delete menu function not implemented yet.\n";
                break;
            case 5:
                cout << "Add customer order function not implemented yet.\n";
                break;
            case 6:
                cout << "Display order record function not implemented yet.\n";
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}

int menu() {
    int choice;
    cout << "\n::PROGRAM MENU::\n";
    cout << "1. Add new menu\n";
    cout << "2. Display menu\n";
    cout << "3. Update menu\n";
    cout << "4. Delete menu\n";
    cout << "5. Add customer order\n";
    cout << "6. Display order record\n";
    cout << "7. Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

void newMenu(vector<meal>& Record) {
    meal newMeal;
    cout << "Enter Meal ID: ";
    cin >> newMeal.id;
    cin.ignore(); 
    cout << "Enter Meal Name: ";
    getline(cin, newMeal.name);
    cout << "Enter Meal Price: ";
    cin >> newMeal.price;
    
    Record.push_back(newMeal);
    cout << "New menu item added successfully!\n";
}

void displayMenu(const vector<meal>& Record) {
    int option;
    cout << "Choose display option:\n";
    cout << "1. Display specific meal by ID\n";
    cout << "2. Display all meals\n";
    cout << "Enter option: ";
    cin >> option;
    
    if (option == 1) {
        int searchID;
        cout << "Enter Meal ID: ";
        cin >> searchID;
        
        for (const auto& item : Record) {
            if (item.id == searchID) {
                cout << "Meal ID: " << item.id << " | Name: " << item.name << " | Price: $" << item.price << "\n";
                return;
            }
        }
        cout << "Meal ID not found!\n";
    } else if (option == 2) {
        cout << "\nList of All Meals:\n";
        for (const auto& item : Record) {
            cout << "Meal ID: " << item.id << " | Name: " << item.name << " | Price: $" << item.price << "\n";
        }
    } else {
        cout << "Invalid option!\n";
    }
}
