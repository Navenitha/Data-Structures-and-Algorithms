/*Subject code : CSEB3213 Data Structures & Algorithms
 Section : 01B
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : 2 */
 
#include<iostream>
#include<list>
#include<string>
#include<sstream>
using namespace std;

int main() {
    list<string> greeting {"Hello", "<name>"};
    list<string> word1 {":)", "You have", "X", "credit", "(s)", "more to go."};
    list<string> word2 {"Congratulation!!", "Hang in there!!", "Almost done!!"};
    list<string> wish;

    string name;
    int credit, balance;

    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter current total credit : ";
    cin >> credit;

    
    balance = 120 - credit;

   
    for (auto it = greeting.begin(); it != greeting.end(); ++it) {
        if (*it == "<name>") {
            *it = name;
            break;
        }
    }

    
    for (auto it = greeting.begin(); it != greeting.end(); ++it) {
        wish.push_back(*it);
    }

    
    stringstream ss;
    ss << balance;
    string balanceStr = ss.str();

   
    for (auto it = word1.begin(); it != word1.end(); ++it) {
        if (*it == "X") {
            *it = balanceStr;
            break;
        }
    }

    
    for (auto it = word1.begin(); it != word1.end(); ++it) {
        wish.push_back(*it);
    }

    
    if (balance == 0) {
        
        wish.push_back(word2.front());
    }
    else if (balance < 60) {
       
        auto it = word2.begin();
        advance(it, 2); 
        wish.push_back(*it);
    }
    else if (balance > 60) {
       
        auto it = word2.begin();
        advance(it, 1); 
        wish.push_back(*it);
    }

   
    cout << "\nResult:\n";
    for (auto x : wish)
        cout << x << " ";

    return 0;
}
