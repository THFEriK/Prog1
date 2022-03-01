/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "./std_lib_facilities.h"

class B1{
    public:
        void f(){
            cout << "B::f\n";
        }
        virtual void vf(){
            cout << "B::vf\n";
        }
        virtual void pvf() = 0; 
};

class D1 : public B1{
    public:
        void vf() const{
            cout << "D:B::f\n";
        }
        void f(){
            cout << "D:B::f\n";
        }
        void pvf() override{};

};

class D2 : public D1{
    public:
        void pvf() override{};
};

class B2{
    public:
        virtual void pvf() = 0;
};

class D21 : public B2{
    public:
        string data = "data";
        void pvf() override{
            cout << data << endl;
        };
};

class D22 : public B2{
    public:
        int value = 1337;
        void pvf() override{
            cout << value << endl;
        };
};

void f(B2& obj){
    obj.pvf();
}

int main()
{
    //Absztrakt osztályt nem lehet deklarálni
    /*B1 obj;
    obj.f();
    obj.vf();*/

    D1 obj2;
    obj2.f();
    obj2.vf();

    B1& obj3 = obj2;
    obj3.f();
    obj3.vf();

    D2 obj4;
    obj4.f();
    obj4.vf();
    obj4.pvf();

    D21 d21;
    D22 d22;
    f(d21);
    f(d22);
}

/*class Shape {
    // deals with color and style and holds sequence of lines
    public:
    void draw() const;
    // deal with color and draw lines
    virtual void move(int dx, int dy);
    // move the shape +=dx and +=dy
    void set_color(Color col);
    Color color() const;
    void set_style(Line_style sty);
    Line_style style() const;
    void set_fill_color(Color col);
    Color fill_color() const;
    Point point(int i) const;
    int number_of_points() const;
    // read-only access to points
    Shape(const Shape&) = delete;
    // prevent copying
    Shape& operator=(const Shape&) = delete;
    virtual ~Shape() { }
    protected:
    Shape() { }
    Shape(initializer_list<Point> lst);
    // add() the Points to this Shape
    virtual void draw_lines() const;
    // draw the appropriate lines
    void add(Point p);
    // add p to points
    void set_point(int i, Point p);
    // points[i]=p;
    private:
    vector<Point> points;
    // not used by all shapes
    Color lcolor {fl_color()}; // color for lines and characters (with default)
    Line_style ls {0};
    Color fcolor {Color::invisible};
    // fill color
};*/