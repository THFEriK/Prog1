/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "../lib/std_lib_facilities.h"

class B1{
    public:
        void f(){
            cout << "B::f\n";
        }
        virtual void vf(){
            cout << "B::vf\n";
        }
};

class D1 : B1{
    public:
        void vf() const{
            cout << "D:B::f\n";
        }
        void f(){
            cout << "D:B::f\n";
        }
};

int main()
{
    B1 obj;
    obj.f();
    obj.vf();

    D1 obj2;
    obj2.f();
    obj2.vf();
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