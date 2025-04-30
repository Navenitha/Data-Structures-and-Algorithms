/*Subject code : CSEB3213 Data Structures and Algorithms
 Section : 01B 
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : Q2 */
 
#include <iostream>
#include <stack>
using namespace std;


void grading(stack<float> marks) {
    int count = 1;
    int totalPass = 0, totalFail = 0;

    cout << "\n:: Grading ::" << endl;
    while (!marks.empty()) {
        float mark = marks.top();
        cout << "Mark " << count << " : " << mark;
        if (mark >= 50.0) {
            cout << " (Pass)" << endl;
            totalPass++;
        } else {
            cout << " (Fail)" << endl;
            totalFail++;
        }
        marks.pop();
        count++;
    }

    cout << "Total Pass : " << totalPass << " students." << endl;
    cout << "Total Fail : " << totalFail << " students." << endl;
}

void popAll(stack<float> &marks) {
    cout << "\nRemoving all marks..." << endl;
    while (!marks.empty()) {
        marks.pop();
    }
}

int main() {
    stack<float> marks;
    int size;
    float mark;

    cout << "Enter total data to insert: ";
    cin >> size;

    for (int i = 1; i <= size; i++) {
        cout << "Enter mark : ";
        cin >> mark;
        marks.push(mark); 
    }

    grading(marks);       
    popAll(marks);        

    if (marks.empty())
        cout << "[Result] All marks have been deleted." << endl;

    cout << "\nEnd of program";
    return 0;
}
