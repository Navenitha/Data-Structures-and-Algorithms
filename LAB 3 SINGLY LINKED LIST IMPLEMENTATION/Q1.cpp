/*Subject code : CSEB3213 Data Structures and Algorithms
 Section : 01B 
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : Q1 */
 
 
#include <iostream>
using namespace std;

class Record {
public:
    int year;
    Record* next; 
};


Record* createNode() {
    Record* n = new Record();
    cout << "Enter year : ";
    cin >> n->year;
    n->next = NULL;
    return n;
}


void insertNode(Record*& head) {
    Record* n;
    Record* tail = NULL;
    char choice;

    do {
        n = createNode();
        
        if (head == NULL) {
            head = n;
            tail = n;
        }
        
        else {
            tail->next = n;
            tail = n;
        }
        cout << "Press [y] for new record:";
        cin >> choice;
    } while (choice == 'y');
    cout << endl;
}

void display(Record* head) {
    cout << "All records : ";
    Record* temp = head;
    while (temp != NULL) {
        cout << temp->year << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Record* head = NULL;
    insertNode(head);
    display(head);
    return 0;
}
