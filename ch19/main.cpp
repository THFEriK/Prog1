/*
    g++ main.cpp -o "main" && ./main
*/

#include <iostream>
#include <vector>

template<typename T>
struct S { 
    private:
        T val;

    public:
        S(T v) : val(v){ }
        T get() const;
        T get();
        //void set(T v);
        void operator=(const T& v);
};

template<typename T>
T S<T>::get() const{
    return val;
}

template<typename T>
T S<T>::get(){
    return val;
}

/*template<typename T>
void S<T>::set(T v){
    val = v;
}*/

template<typename T>
void S<T>::operator=(const T& v){
    val = v;
}

template<typename T>
void read_val(T& v){
    std::cin >> v;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

int main(){
    using namespace std;

    S<int>         t1 = 10;
    S<char>        t2 = 'a';
    S<double>      t3 = 9.9;
    S<string>      t4 = {"Alma"};
    S<std::vector<int>> t5 = {{10}};

    cout << "t1=: " << t1.get() << endl ;
    cout << "t2=: " << t2.get() << endl ;
    cout << "t3=: " << t3.get() << endl ;
    cout << "t4=: " << t4.get() << endl ;
    cout << "t5=: " << t5.get()[0] << endl ;

    t1 = 5;
    cout << "t1=: " << t1.get() << endl ;

    int         tr1;
    char        tr2;
    double      tr3;
    string      tr4;


    cout << "Int: ";
    read_val(tr1);
    S<int> tv1 {tr1};
    
    cout << "char: ";
    read_val(tr2);
    S<char> tv2 {tr2};
    cout << "double: ";
    read_val(tr3);
    S<double> tv3 {tr3};
    cout << "string: ";
    read_val(tr4);
    S<string> tv4 {tr4};

    /*
    int vtr1;
    int vtr2;
    int vtr3;

    cout << "vector<int>" << endl;
    cout << "val1:";
    read_val(vtr1);
    cout << "val2:";
    read_val(vtr2);
    cout << "val1:";
    read_val(vtr3);
    
    S<std::vector<int>> tv5 = {{vtr1, vtr2, vtr3}};
    */

    /*
    cout << endl;
    cout << "tv1=: " << tv1.get() << endl ;
    cout << "tv2=: " << tv2.get() << endl ;
    cout << "tv3=: " << tv3.get() << endl ;
    cout << "tv4=: " << tv4.get() << endl ;
    cout << "tv5=: " << tv5.get()[0] << ", "
                     << tv5.get()[1] << ", "
                     << tv5.get()[2] << endl ;
    */

    std::vector<int> tv5;

    cout << "vector<int> Format: {val,val,val}"
    cin >> tv5;
    cout << tv5;


    return 0;
}