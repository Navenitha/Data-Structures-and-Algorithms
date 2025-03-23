/*Subject code : CSEB3213 Data Structures & Algorithms
 Section : 01B
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : 1 */ 
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void insert(vector<string> &dessert, vector<string> &mainCourse) {
    int choice;
    string newItem;
    cout << "Press [1] for dessert and [2] for main course: ";
    cin >> choice;
    cin.ignore(); 
    
    if (choice == 1) {
        cout << "Enter new dessert item: ";
        getline(cin, newItem);
        dessert.push_back(newItem);
        sort(dessert.begin(), dessert.end()); 
    } else if (choice == 2) {
        cout << "Enter new main course: ";
        getline(cin, newItem);
        mainCourse.push_back(newItem);
        sort(mainCourse.begin(), mainCourse.end()); 
    } else {
        cout << "Invalid choice!" << endl;
    }
}


bool searchItem(const vector<string> &menu, const string &item) {
    return find(menu.begin(), menu.end(), item) != menu.end();
}

void display(const vector<string> &dessert, const vector<string> &mainCourse) {
    cout << "List of dessert : ";
    for (const auto &item : dessert) {
        cout << item << " | ";
    }
    cout << endl;

    cout << "List of main course : ";
    for (const auto &item : mainCourse) {
        cout << item << " | ";
    }
    cout << endl;
}

int main() {
    vector<string> dessert = {"pie", "cake", "scone", "croffle", "puff"};
    vector<string> mainCourse = {"meatballs", "greek lamb"};

    sort(dessert.begin(), dessert.end());
    sort(mainCourse.begin(), mainCourse.end());

    cout << "::Menu::" << endl;
    display(dessert, mainCourse);

    cout << "\n::Adding New Menu::" << endl;
    insert(dessert, mainCourse);

    cout << "\n::Updated Menu::" << endl;
    display(dessert, mainCourse);

    string searchQuery;
    cout << "\nEnter an item to search: ";
    getline(cin, searchQuery);

    if (searchItem(dessert, searchQuery)) {
        cout << searchQuery << " found in desserts." << endl;
    } else if (searchItem(mainCourse, searchQuery)) {
        cout << searchQuery << " found in main courses." << endl;
    } else {
        cout << searchQuery << " not found in the menu." << endl;
    }

    return 0;
}
