#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class straight_cylinder
{
private:
    double bottom_area;
    double height;
    double volume;

public:
    straight_cylinder(double a = 0, double h = 0)
    {
        bottom_area = a;
        height = h;
        volume = a * h;
    }
    void triangle(double side1, double side2, double side3, double h)
    {
        double p = (side1 + side2 + side3) / 2;
        bottom_area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
        height = h;
        volume = bottom_area * h;
    }
    void rectangle(double length, double width, double h)
    {
        bottom_area = length * width;
        height = h;
        volume = bottom_area * h;
    }
    void circle(double radius, double h)
    {
        bottom_area = M_PI * radius * radius;
        height = h;
        volume = bottom_area * h;
    }
    ~straight_cylinder()
    {
        bottom_area = 0;
        height = 0;
        volume = 0;
    }
    double get_volume()
    {
        return volume;
    }
};

//可以使用继承的方法，但是这里不要求，所以不用继承

int main()
{
    int op;
    while (cin >> op)
    {
        double area;
        double h;
        straight_cylinder sc;
        switch (op)
        {
        case 0:
        {
            double radius;
            cin >> radius >> h;
            area = M_PI * radius * radius;
            sc.circle(radius, h);
            break;
        }
        case 1:
        {
            double edge1, edge2, edge3;
            cin >> edge1 >> edge2 >> edge3 >> h;
            double p = (edge1 + edge2 + edge3) / 2;
            area = sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
            sc.triangle(edge1, edge2, edge3, h);
            break;
        }
        case 2:
        {
            double length, width;
            cin >> length >> width >> h;
            area = length * width;
            sc.rectangle(length, width, h);
            break;
        }
        }
        cout << fixed << setprecision(2) << sc.get_volume() << endl;
    }
    return 0;
}