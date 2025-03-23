/*Subject code : CSEB3213 Data Structures & Algorithms
 Section : 01B
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : 2 */ 
 
#include <iostream>
#include <vector>
using namespace std;

void display(const vector<float>& area) {
    for (auto rit = area.rbegin(); rit != area.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
}

int main() {
    vector<float> width = {2.0, 2.1, 9.3, 7.4, 8.1};
    vector<float> length = {6.0, 2.3, 4.2, 7.4, 9.1};
    vector<float> area;
    
    for (size_t i = 0; i < width.size(); ++i) {
        area.push_back(width[i] * length[i]);
    }
    area.insert(area.begin() + 3, 10.4);
    cout << "List of area in reverse order: ";
    display(area);
    
    return 0;
}
