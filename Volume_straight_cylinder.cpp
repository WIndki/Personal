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

int main()
{
    int op;
    while (cin >> op)
    {
        double area;
        double h;
        switch (op)
        {
        case 0:
        {
            double radius;
            cin >> radius >> h;
            area = M_PI * radius * radius;
            break;
        }
        case 1:
        {
            double edge1, edge2, edge3;
            cin >> edge1 >> edge2 >> edge3 >> h;
            double p = (edge1 + edge2 + edge3) / 2;
            area = sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
            break;
        }
        case 2:
        {
            double length, width;
            cin >> length >> width >> h;
            area = length * width;
            break;
        }
        }
        straight_cylinder sc(area, h);
        cout << fixed << setprecision(2) << sc.get_volume() << endl;
    }
    return 0;
}