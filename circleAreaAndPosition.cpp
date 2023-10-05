#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Circle {
    double radius;
    double centerX;
    double centerY;
};

double calculateArea(Circle circle) {
    return M_PI * circle.radius * circle.radius;
}
//通过值传递方式
// Circle moveCircle(Circle circle, double offsetX, double offsetY) {
//     Circle position;
//     position.centerX = circle.centerX + offsetX;
//     position.centerY = circle.centerY + offsetY;
//     return position;
// }

// int main() {
//     Circle circle,position;
//     double offsetX, offsetY,a,b;
//     while (cin >> circle.radius >> circle.centerX >> circle.centerY >> offsetX >> offsetY) {
//         double area = calculateArea(circle);
//         position = moveCircle(circle, offsetX, offsetY);
//         cout<<fixed << setprecision(2);
//         cout << "area:"<< area << " ";
//         cout << "position:(" <<position.centerX << ",";
//         cout <<  position.centerY << ")" << endl;
//     }

//     return 0;
// }

//通过引用传递
void moveCircle(Circle &circle, double offsetX, double offsetY) {//存放的是由主调函数放进来的实参变量的地址。
//被调函数对形参的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量。
    circle.centerX + offsetX;//直接修改实参
    circle.centerY + offsetY;
}

int main() {
    Circle circle;//声明结构变量
    double offsetX, offsetY;
    while (cin >> circle.radius >> circle.centerX >> circle.centerY >> offsetX >> offsetY) {
        double area = calculateArea(circle);
        moveCircle(circle, offsetX, offsetY);
        cout<<fixed << setprecision(2);
        cout << "area:"<< area << " ";
        cout << "position:(" <<circle.centerX << ",";
        cout <<  circle.centerY << ")" << endl;
    }

    return 0;
}