/*Subject code : CSEB3213 Data Structures and Algorithms
 Section : 01B 
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : Q1 */
 
#include <iostream>
using namespace std;

struct Data {
    float mark;
    Data* next;
};

void push(Data* &head, float mark) {
    Data* n = new Data;
    n->mark = mark;
    n->next = head;
    head = n;
}

void grading(Data* head) {
    int count = 1;
    int totalPass = 0, totalFail = 0;

    cout << "\n:: Grading ::" << endl;
    while (head != NULL) {
        cout << "Mark " << count << " : " << head->mark;
        if (head->mark >= 50.0) {
            cout << " (Pass)" << endl;
            totalPass++;
        } else {
            cout << " (Fail)" << endl;
            totalFail++;
        }
        head = head->next;
        count++;
    }

    cout << "Total Pass : " << totalPass << " students." << endl;
    cout << "Total Fail : " << totalFail << " students." << endl;
}

void pop(Data* &head) {
    cout << "\nRemoving all marks..." << endl;
    while (head != NULL) {
        Data* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Data* head = NULL;
    int size;
    float mark;

    cout << "Enter total data to insert: ";
    cin >> size;

    for (int i = 1; i <= size; i++) {
        cout << "Enter mark : ";
        cin >> mark;
        push(head, mark); 
    }

    grading(head);        
    pop(head);            

    if (head == NULL)
        cout << "[Result] All marks have been deleted." << endl;

    cout << "\nEnd of program";
    return 0;
}
