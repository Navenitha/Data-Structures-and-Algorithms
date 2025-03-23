/*Subject code : CSEB3213 Data Structures & Algorithms
 Section : 01B
 Student name : NAVENITHA A/P JEGANATH
 Student ID no: SW01082804
 Question no : 1 */

#include <iostream>
#include <list>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
    list<float> mylist;
    int i = 0;

    for (; i < 5; i++)
        mylist.push_back(10.0);

    cout << "Total data in record : " << mylist.size() << endl;

    vector<float> myvector(mylist.begin(), mylist.end());
    myvector[2] = 18.0;
    myvector[4] = 5.3;

    cout << "List of data in record: ";
    for (i = 0; i < myvector.size(); i++)
        cout << myvector[i] << " ";

    sort(myvector.begin(), myvector.end());
    cout << "\nData in ascending mode: ";
    for (i = 0; i < myvector.size(); i++)
        cout << myvector[i] << " ";

    sort(myvector.rbegin(), myvector.rend());
    cout << "\nData in descending mode: ";
    for (i = 0; i < myvector.size(); i++)
        cout << myvector[i] << " ";

    return 0;
}
