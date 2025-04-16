/*Subject code : CSEB3213 Data Structures and Algorithms
 Section : 01B 
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : Q3 */
 
 
#include <iostream>
using namespace std;

struct Subject {
    string sname, scode, remark = "Normal";
    int credit;
    float fee;
    Subject* next; 
};

Subject* head = nullptr;

int menu() {
    int choice;
    cout << "\n::SUBJECT REGISTRATION::\n";
    cout << "1. Add subject\n";
    cout << "2. Display subject\n";
    cout << "3. Update subject (Not implemented)\n";
    cout << "4. Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}


Subject* subjectInfo() {
    cin.ignore(); 
    Subject* newSubject = new Subject;

    cout << "Enter subject name: ";
    getline(cin, newSubject->sname);

    cout << "Enter subject code: ";
    getline(cin, newSubject->scode);

    cout << "Enter credit hours: ";
    cin >> newSubject->credit;

    char late;
    cout << "Is this a late registration? (y/n): ";
    cin >> late;

    if (late == 'y' || late == 'Y') {
        newSubject->fee = newSubject->credit * 500.0 + 100.0;
        newSubject->remark = "Late Registration";
    } else {
        newSubject->fee = newSubject->credit * 500.0;
    }

    newSubject->next = nullptr;
    return newSubject;
}


void registerSubject() {
    cout << "\n:: Add Subject Record ::\n";
    Subject* newNode = subjectInfo();

    if (head == nullptr) {
        head = newNode;
    } else {
        Subject* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Subject added successfully!\n";
}


void display() {
    cout << "\n:: Display Subject Record ::\n";
    int option;
    cout << "Press [1] for individual subject or [2] for all subjects: ";
    cin >> option;

    if (option == 1) {
        cin.ignore(); 
        string code;
        cout << "Enter subject code: ";
        getline(cin, code);

        Subject* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->scode == code) {
                cout << "\nSubject Name: " << temp->sname << endl;
                cout << "Subject Code: " << temp->scode << endl;
                cout << "Credit Hours: " << temp->credit << endl;
                cout << "Fee: RM" << temp->fee << endl;
                cout << "Remark: " << temp->remark << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "Subject with code " << code << " not found.\n";

    } else if (option == 2) {
        Subject* temp = head;
        if (temp == nullptr) {
            cout << "No subjects registered.\n";
            return;
        }
        while (temp != nullptr) {
            cout << "\nSubject Name: " << temp->sname << endl;
            cout << "Subject Code: " << temp->scode << endl;
            cout << "Credit Hours: " << temp->credit << endl;
            cout << "Fee: RM" << temp->fee << endl;
            cout << "Remark: " << temp->remark << endl;
            temp = temp->next;
        }
    } else {
        cout << "Invalid option.\n";
    }
}


int main() {
    string name, idNo;
    int choice;

    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student ID no: ";
    getline(cin, idNo);

    do {
        choice = menu();
        switch (choice) {
            case 1:
                registerSubject();
                break;
            case 2:
                display();
                break;
            case 3:
                cout << "Update feature not implemented yet.\n";
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
