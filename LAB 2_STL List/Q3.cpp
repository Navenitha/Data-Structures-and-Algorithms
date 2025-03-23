/*Subject code : CSEB3213 Data Structures & Algorithms
 Section : 01B
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : 3 */
 
#include<iostream>
#include<list>
#include<string>
#include<iomanip> 
using namespace std;

struct Record {
    string name;
    double weight;
    double protein;
};

void dataWeight(list<Record>& records) {
    char cont;
    do {
        Record temp;
        cout << "Enter Name: ";
        cin.ignore(); 
        getline(cin, temp.name);
        cout << "Enter weight (kg): ";
        cin >> temp.weight;

        records.push_back(temp);

        cout << "Press [Y] for next input: ";
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');
}


void dataProtein(list<Record>& records) {
    for (auto& rec : records) {
        rec.protein = rec.weight * 0.8;
    }
}


void displayData(const list<Record>& records) {
    cout << "\nList of Records:\n";
    int count = 1;
    cout << fixed << setprecision(2);
    for (const auto& rec : records) {
        cout << count << ". Name: " << rec.name
             << ", Weight (kg): " << rec.weight
             << ", Protein required (gram): " << rec.protein << endl;
        count++;
    }
}


void updateData(list<Record>& records) {
    char choice;
    cout << "\nWould you like to update specific data [Press Y for Yes]: ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        string searchName;
        double newWeight;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, searchName);
        cout << "Enter new weight input (kg): ";
        cin >> newWeight;

        
        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->name == searchName) {
                it->weight = newWeight;
                it->protein = newWeight * 0.8;
                break;
            }
        }
    }
}

int main() {
    list<Record> records;

  
    dataWeight(records);
    dataProtein(records);
    displayData(records);

    
    updateData(records);
    displayData(records);

    cout << "\nEnd of program.\n";
    return 0;
}
