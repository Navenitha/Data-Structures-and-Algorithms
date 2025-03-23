/*Subject code : CSEB3213 Data Structures & Algorithms
 Section : 01B
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : 4 */
 
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Menu {
    int mealID;
    string mealName;
    float mealPrice;
};

struct Order {
    int quantity;
    string custName;
    string mealName;
    float totalPayment;
};

vector<Menu> menuList;
vector<Order> orderList;


void displayMenu() {
    cout << "\n--- MENU LIST ---\n";
    cout << left << setw(10) << "Meal ID" << setw(20) << "Meal Name" << setw(10) << "Price\n";
    for (const auto& item : menuList) {
        cout << left << setw(10) << item.mealID << setw(20) << item.mealName << fixed << setprecision(2) << item.mealPrice << endl;
    }
    cout << endl;
}


void updateMenu() {
    int id, choice;
    cout << "\nEnter Meal ID to update: ";
    cin >> id;
    bool found = false;

    for (auto& item : menuList) {
        if (item.mealID == id) {
            found = true;
            cout << "1. Update Meal Name\n2. Update Meal Price\nChoose option: ";
            cin >> choice;
            cin.ignore(); 

            if (choice == 1) {
                cout << "Enter new Meal Name: ";
                getline(cin, item.mealName);
                cout << "Meal name updated successfully.\n";
            } else if (choice == 2) {
                cout << "Enter new Meal Price: ";
                cin >> item.mealPrice;
                cout << "Meal price updated successfully.\n";
            } else {
                cout << "Invalid option.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Meal ID not found.\n";
    }
}


void deleteMenu() {
    int id;
    cout << "\nEnter Meal ID to delete: ";
    cin >> id;
    bool deleted = false;

    for (auto it = menuList.begin(); it != menuList.end(); ++it) {
        if (it->mealID == id) {
            menuList.erase(it);
            deleted = true;
            cout << "Meal deleted successfully.\n";
            break;
        }
    }

    if (!deleted) {
        cout << "Meal ID not found.\n";
    }
}


void customerOrder() {
    int id, qty;
    string name;
    bool found = false;

    cout << "\nEnter Meal ID to order: ";
    cin >> id;

    for (const auto& item : menuList) {
        if (item.mealID == id) {
            found = true;
            cin.ignore(); 
            cout << "Enter Customer Name: ";
            getline(cin, name);
            cout << "Enter Quantity: ";
            cin >> qty;

            float total = qty * item.mealPrice;

            Order newOrder = {qty, name, item.mealName, total};
            orderList.push_back(newOrder);

            cout << "Order placed successfully. Total Payment: RM" << fixed << setprecision(2) << total << endl;
            break;
        }
    }

    if (!found) {
        cout << "Meal ID not found.\n";
    }
}


void displayRecord() {
    cout << "\n--- CUSTOMER ORDERS ---\n";
    cout << left << setw(20) << "Customer Name" << setw(15) << "Meal Name" << setw(10) << "Quantity" << setw(15) << "Total Payment\n";

    for (const auto& order : orderList) {
        cout << left << setw(20) << order.custName << setw(15) << order.mealName << setw(10) << order.quantity << fixed << setprecision(2) << "RM" << order.totalPayment << endl;
    }
}


int main() {
    int choice;

 
    menuList.push_back({1, "Nasi Lemak", 5.00});
    menuList.push_back({2, "Mee Goreng", 4.50});
    menuList.push_back({3, "Chicken Rice", 6.00});

    do {
        cout << "\n--- MENU MANAGEMENT SYSTEM ---\n";
        cout << "1. Display Menu\n2. Update Menu\n3. Delete Menu\n4. Customer Order\n5. Display Orders\n0. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: displayMenu(); break;
            case 2: updateMenu(); break;
            case 3: deleteMenu(); break;
            case 4: customerOrder(); break;
            case 5: displayRecord(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
