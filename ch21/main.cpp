#include <vector>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>

struct Item{
    int iid;
    std::string name;
    double value;
    /*....*/
};

std::istream& operator>>(std::istream& is, Item& i){
    is >> i.iid >> i.name >> i.value;
    return is;
}

std::ofstream& operator<<(std::ofstream& os, Item& i){
    os << i.iid << " " << i.name << " " << i.value << "\n";
    return os;
}

void fill_file(){
    std::string fname = "data.txt";
    std::ofstream of( fname );
    Item ii;
    for(int i = 0; i < 10; i++){
        ii.iid = i;
        ii.name = std::to_string(i)+"N";
        ii.value = i*i;

        of << ii;
    }
}

int main(){
    using namespace std;
    fill_file();

    vector<Item> vi;

}