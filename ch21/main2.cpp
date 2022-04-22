#include <vector>
#include <list>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <map>
#include <numeric>

template<typename T, typename Z>
void m_print(const std::map<T,Z>& m)
{
    std::cout << "\nMap:\n";

    for (const auto& a : m)
        std::cout << a.first << " => " << a.second << '\n';

    std::cout << '\n';
}

std::istream& operator>>(std::istream& is, std::map<std::string,int>& m){
    std::string key;
    int value;

    is >> key >> value;
    m.insert(std::make_pair(key, value));
    return is;
}

void read_to_map(std::map<std::string,int>& m, int num){
    while(m.size() < num)
        std::cin >> m;
}

int main(){
    using namespace std;

    //1. & 2.
    std::map<std::string,int> msi;
    msi["Tojasrantotta"] = 1;
    msi["Gulyásleves"] = 2;
    msi["Bakonyi"] = 3;
    msi["Töltöttkáposzta"] = 4;
    msi["Zsíroskenyér"] = 5;
    msi["Pizza"] = 6;
    msi["Húsleves"] = 7;
    msi["Halászlé"] = 8;
    msi["Lencsefőzelék"] = 9;
    msi["Pacal"] = 10;

    //3.
    m_print(msi);

    //4.
    msi.erase(msi.begin(), msi.end());

    //5. & 6.
    read_to_map(msi, 10);

    //7.
    m_print(msi);

    //8.
    int sum = 0;

    for(const auto& a : msi){
        sum += a.second;
    }
    std::cout << "Sum of the values in msi =: " << sum << '\n';

    //9.
    std::map<int, std::string> mis;

    //10.
    for(const auto& a : msi){
        mis.insert(std::make_pair(a.second, a.first));
    }

    //11.
    m_print(mis);

}