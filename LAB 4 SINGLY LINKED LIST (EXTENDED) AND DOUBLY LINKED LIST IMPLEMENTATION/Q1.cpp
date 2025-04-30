/*Subject code : CSEB3213 Data Structures and Algorithms
 Section : 01B 
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : Q1 */
 
#include <iostream>
using namespace std;

struct Node {
    int year;
    Node* next;
};

void insert(Node*& head, Node*& tail, int year) {
    Node* newNode = new Node();
    newNode->year = year;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void display(Node* head) {
    Node* temp = head;
    cout << "All records : ";
    while (temp != nullptr) {
        cout << temp->year << " ";
        temp = temp->next;
    }
    cout << endl;
}

void analysis(Node* head) {
    Node* temp = head;
    int leapCount = 0, nonLeapCount = 0;

    cout << "\n:: Analysis ::" << endl;
    while (temp != nullptr) {
        cout << temp->year << " : ";
        if (isLeap(temp->year)) {
            cout << "leap year" << endl;
            leapCount++;
        } else {
            cout << "non-leap year" << endl;
            nonLeapCount++;
        }
        temp = temp->next;
    }

    cout << "\nTotal leap year : " << leapCount << endl;
    cout << "Total non-leap year : " << nonLeapCount << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr; 
    char choice;
    int year;

    do {
        cout << "Enter year : ";
        cin >> year;
        insert(head, tail, year); 
        cout << "Press [y] for new input:";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << endl;
    display(head);
    analysis(head);

    return 0;
}
