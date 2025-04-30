/*Subject code : CSEB3213 Data Structures and Algorithms
 Section : 01B 
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : Q3 */
 
#include <iostream>
using namespace std;

struct Employee {
    string name;
    float salary;
    int yearOfService;
    Employee* next;
    Employee* prev;
};

Employee* head = nullptr;

void insert(string name[], float salary[], int service[], int size) {
    Employee* temp = nullptr;
    for (int i = 0; i < size; i++) {
        Employee* newNode = new Employee;
        newNode->name = name[i];
        newNode->salary = salary[i];
        newNode->yearOfService = service[i];
        newNode->next = nullptr;
        newNode->prev = temp;

        if (temp != nullptr)
            temp->next = newNode;
        else
            head = newNode;

        temp = newNode;
    }
}

void update(string empName, float newSalary) {
    Employee* temp = head;
    while (temp != nullptr) {
        if (temp->name == empName) {
            temp->salary = newSalary;
            break;
        }
        temp = temp->next;
    }
}

void display() {
    if (head == nullptr || head->next == nullptr) return;

    Employee* first = head;
    Employee* second = head->next;

    first->next = second->next;
    if (second->next != nullptr)
        second->next->prev = first;

    second->prev = nullptr;
    second->next = first;
    first->prev = second;
    head = second;

    cout << "\nUpdated List of Employee\n";
    cout << "------------------------------------------------------------------\n";
    Employee* temp = head;
    int index = 1;
    while (temp != nullptr) {
        cout << index++ << ". Staff Name : " << temp->name
             << ", Salary : RM " << temp->salary
             << ", Year of Service : " << temp->yearOfService << endl;
        temp = temp->next;
    }
}

int main() {
    string name[] = {"Ahmad", "Siew May", "Ravi", "John", "Mohammad", "Jennifer"};
    float salary[] = {12000.0, 4800.0, 6000.0, 5500.0, 14000.0, 11000.0};
    int service[] = {10, 4, 12, 7, 6, 5};
    int size = 6;

    insert(name, salary, service, size);

    cout << "\n# Menu : Update Salary #\n";
    string Name;
    float newSalary;
    cout << "Enter name : ";
    getline(cin, Name);
    cout << "Enter new salary : RM";
    cin >> newSalary;

    update(Name, newSalary);

    cout << "Swap position of Ahmad's and Siew May's record\n";
    display();

    cout << "\nEnd of program\n";
    return 0;
}
