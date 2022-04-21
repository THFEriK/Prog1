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

std::ostream& operator<<(std::ostream& os, Item& i){
    os << i.iid << " " << i.name << " " << i.value << "\n";
    return os;
}

//6.
class Cmp_by_name {
    std::string name;
public:
    Cmp_by_name(const std::string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

//7.
class Cmp_by_iid {
    int iid;
public:
    Cmp_by_iid(const int& nn) : iid{nn} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};

//******************************************************************
int main(){
    using namespace std;

    //1.
    std::vector<Item> vi;
    std::ifstream ist {"data.txt"};

    if (!ist) throw std::runtime_error("File is not found");
    for (Item v; ist >> v; ){
        vi.push_back(v);
    }
    ist.close();

    cout << "Alap vector:\n";
    for(Item val : vi){
        std::cout << val;
    }

    //2.
    cout << "\nRendezett vector (name):\n";
    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.name < b.name; });

    for(Item val : vi){
        std::cout << val;
    }

    //3.
    cout << "\nRendezett vector (iid):\n";
    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.iid < b.iid; });

    for(Item val : vi){
        std::cout << val;
    }

    //4.
    cout << "\nRendezett vector (value):\n";
    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.value > b.value; });

    for(Item val : vi){
        std::cout << val;
    }

    //5.
    vi.push_back({99,"horse shoe",12.34});
    vi.push_back({9988,"Canon S400", 499.95});

    cout << "\nHozzáadott sorokkal:\n";
    for(Item val : vi){
        std::cout << val;
    }

    // 6.
    vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_name("horse shoe")));

    cout << "\nTörölt sor(name):\n";
    for(Item val : vi){
        std::cout << val;
    }

    // 7.
    vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_iid(9988)));

    cout << "\nTörölt sor(id):\n";
    for(Item val : vi){
        std::cout << val;
    }

    //8. Ugyan ez Listával
    //1.
    std::list<Item> li;
    std::ifstream ist2 {"data.txt"};

    if (!ist2) throw std::runtime_error("File is not found");
    for (Item l; ist2 >> l; ){
        li.push_back(l);
    }
    ist2.close();

    //8/2.
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });

    //8/3.
    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });

    //8/4.
    //std::sort(li.begin(), li.end(), [](const Item& a, const Item& b) { return a.value > b.value; });
    li.sort([](const Item& a, const Item& b) { return a.value > b.value; });

    //8/5.
    Item tmp = Item{99,"horse shoe",12.34};
    li.push_back(tmp);
    tmp = Item{9988,"Canon S400", 499.95};
    li.push_back(tmp);

    //8/6.
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_name("horse shoe")));

    //8/7.
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_iid(9988)));

    std::cout << "\nFinal list:\n";
    for(Item val : li) {
        std::cout << val;
    }
}