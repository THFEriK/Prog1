/*
    g++ main2.cpp -o "main2"
*/
#include "std_lib_facilities.h"

void CheckName(string name){
    for (char c : name) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("Bad character in names");
                break;
            default:
                break;
        }
    }
}
void CheckAge(int age){
    if (age < 0 || 150 < age) error("Invalid age");
}
void error(string s)
{
    throw runtime_error(s);
}


struct Person{
    private:
        string first_name;
        string last_name;
        int age;

    public:
        Person(){}
        Person(string fn, string ln, int a) : first_name(fn), last_name(ln), age(a){
            CheckName(fn+ln);
            CheckAge(a);
        }
        string GetFullName() const{
            return first_name+" "+last_name;
        }
        string GetFirstName() const{
            return first_name;
        }
        string GetLastName() const{
            return last_name;
        }
        int GetAge() const{
            return age;
        }
};

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "FullName: "
              << p.GetFullName()
              << "\nAge: "
              << p.GetAge()
              << "\n\n";
}

istream& operator>>(istream& is, Person& p)
{
    string f;
    string l;
    int a;
    
    cout << "FirstName: ";
    is >> f;
    cout << "LastName: ";
    is >> l;
    cout << "Age: ";
    is >> a;

    p = Person(f, l, a);

    return is;
}

int main()
{
    using namespace std;

    try{
        vector<Person> pvec;
        cout << "Enter some person. Terminate with 'end' name\n";

        for (Person p; cin >> p; ) {
            if (p.GetFirstName() == "end" || p.GetLastName() == "end") break;
            pvec.push_back(p);
        }

        for (Person p : pvec)
            cout << p << endl;
    }
    catch(exception& e){
        cerr << e.what() << endl;
    }
}