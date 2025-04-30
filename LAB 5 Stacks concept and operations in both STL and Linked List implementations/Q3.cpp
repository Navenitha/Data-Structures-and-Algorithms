/*Subject code : CSEB3213 Data Structures and Algorithms
 Section : 01B 
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : Q3 */
 
#include <iostream>
#include <stack>
using namespace std;

void decimalToBinary(int number) {
    stack<int> binaryStack;

    while (number > 0) {
        binaryStack.push(number % 2);
        number /= 2;
    }

    cout << "Binary number : ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }
    cout << endl;
}

int main() {
    int number;

    cout << ":: Decimal-Binary Converter ::" << endl;

    do {
        cout << "Enter a decimal number [larger than 0] : ";
        cin >> number;
    } while (number <= 0);

    cout << "\nDecimal number : " << number << endl;

    decimalToBinary(number);

    cout << "\nThank you.";
    return 0;
}
