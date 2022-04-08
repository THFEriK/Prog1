/*
    g++ main.cpp -o "main" && ./main
*/

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

template<typename Iter1, typename Iter2>
Iter2 tcopy(Iter1 f1, Iter1 e1, Iter2 f2){
    while(e1 != f1)
    {
        *f2 = *f1;
        f1++;
        f2++;
    }
    return f2;
}


int main(){
    using namespace std;

    const int size = 10;

    //1.
    array<int, size> arr;
    for(int i = 0; i < size; i++)
        arr[i] = i;

    //2.
    vector<int> vec;
    for(int i = 0; i < size; i++)
        vec.push_back(i);

    //3.
    list<int> lst;
    for(int i = 0; i < size; i++)
        lst.push_back(i);

    //4.
    array<int, size> arr_cp = arr;
    vector<int> vec_cp = vec;
    list<int> lst_cp = lst;

    //5.
    for(array<int, size>::iterator p = arr.begin(); p != arr.end(); p++)
        *p +=2;
    for(vector<int>::iterator p = vec.begin(); p != vec.end(); p++)
        *p +=3;
    for(list<int>::iterator p = lst.begin(); p != lst.end(); p++)
        *p +=5;

    //7.
    tcopy(arr.begin(),arr.end(),vec.begin());
    tcopy(lst.begin(),lst.end(),arr.begin());

    //8.
    vector<int>::iterator vec_it = find(vec.begin(), vec.end(), 3);
    if(vec_it != vec.end())
        cout << distance(vec.begin(), vec_it) << endl;
    else
        cout << "null" << endl;

    list<int>::iterator lst_it = find(lst.begin(), lst.end(), 27);
    if(lst_it != lst.end())
        cout << distance(lst.begin(), lst_it) << endl;
    else
        cout << "null" << endl;

    return 0;
}