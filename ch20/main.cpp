/*
    g++ main.cpp -o "main" && ./main
*/

#include <iostream>
#include <vector>
#include <list>

int main(){
    using namespace std;

    int arr1[10];
    vector<int> vec1;
    list<int> lst1;

    for(int i = 0; i < 10; i++){
        arr1[i] = i;
        vec1.push_back(i);
        lst1.push_back(i);
    }

    for(int i = 0; i < 10; i++)
    {
        arr1[i] = arr1[i] + 2;
        vec1[i] = vec1[i] + 3;
    }

    list<int>::iterator p = lst1.begin();
    while(p != lst1.end()) {
        *p = *p + 5;
        p++;
    }

    cout << "Array: { ";
    for(int i = 0; i < 10; i++)
        cout << arr1[i] << (i < 9 ? ", " : "");
    cout << " }" << endl;

    cout << "Vector: { ";
    for(int i = 0; i < 10; i++)
        cout << vec1[i] << (i < 9 ? ", " : "");
    cout << " }" << endl;

    cout << "List: { ";
    p = lst1.begin();
    while(p != lst1.end()) {
        cout << *p << ", ";
        p++;
    }
    cout << " }" << endl;

    return 0;
}