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

int main(){
    using namespace std;

    S<int>         t1 = 10;
    S<char>        t2 = 'a';
    S<double>      t3 = 9.9;
    S<string>      t4 = {"Alma"};
    S<vector<int>> t5 = {{10}};

    cout << "t1=: " << t1.get() << endl ;
    cout << "t2=: " << t2.get() << endl ;
    cout << "t3=: " << t3.get() << endl ;
    cout << "t4=: " << t4.get() << endl ;
    cout << "t5=: " << t5.get()[0] << endl ;

    t1 = 5;
    cout << "t1=: " << t1.get() << endl ;
    return 0;
}