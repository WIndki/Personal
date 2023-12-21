#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point {
public:
    double x, y;
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void translate(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void rotate(double ref_x, double ref_y, double angle) {
        double radians = angle * M_PI / 180.0; //转为弧度制
        double x_ = ref_x + (x - ref_x) * cos(radians) - (y - ref_y) * sin(radians);//X=(x-refx)•cosa-(y-refy)•sina+refx
        double y_ = ref_y + (x - ref_x) * sin(radians) + (y - ref_y) * cos(radians);//Y=(x-refx)•sina+(y-refy)•cosa+refy
        x = x_;
        y = y_;
    }
};

int main() {
    double x, y, op, arg1, arg2, angle;
    while (cin >> x >> y >> op) {
        Point p(x, y);
        if (op == 1) {
            cin >> arg1 >> arg2;
            p.translate(arg1, arg2);
        } else if (op == 2) {
            cin >> arg1 >> arg2 >> angle;
            p.rotate(arg1, arg2, angle);
        }
        cout << fixed << setprecision(2) << "(" << p.x << "," << p.y << ")" << endl;
    }
    return 0;
}
