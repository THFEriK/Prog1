/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <utility>
int main()
{
    using namespace Graph_lib;

    Simple_window win {{100,100},1000,800,"Simple_window"};

    int xmax = 800;
    int ymax = 800;
    int xgrid = 100;
    int ygrid = 100;

    Lines grid;
    for (int x=xgrid; x<=xmax; x+=xgrid)
        grid.add(Point{x,0},Point{x,ymax}); //v
    for (int y = ygrid; y<=ymax; y+=ygrid)
        grid.add(Point{0,y},Point{xmax,y});     //h
    Vector_ref<Rectangle> vr;

    int val1 = 0;
    int val2 = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
        {
            vr.push_back(new Rectangle{Point{val2*100,val1*100},100,100});
            val2++;
            val1++;
            vr[vr.size()-1].set_fill_color(Color::red);
            win.attach(vr[vr.size()-1]);
        }

    Image img1 {Point{300,100},"photo.jpg"};
    Image img2 {Point{300,100},"photo.jpg"};
    Image img3 {Point{500,300},"photo.jpg"};
    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.attach(grid);
    Image img4(Point(0,0),"photo.jpg");
    img4.set_mask(Point(200,0),100,100);
    win.attach(img4);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            win.wait_for_button();
            if (j < 7) img4.move(100,0);
            else img4.move(-700,100);
        }
    }
}