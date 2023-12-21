#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double radius; 
    double circleCenterX; 
    double circleCenterY; 

public:
    Circle(double r, double x, double y) {
        radius = r;
        circleCenterX = x;
        circleCenterY = y;
    }

    double calculateArea() {
        double area = M_PI * radius * radius;
        return area;
    }

    double calculatePerimeter() {
        double perimeter = 2 * M_PI * radius;
        return perimeter;
    }

    void checkPoint(double x, double y) {
        double distanceToCircleCenter = sqrt((x - circleCenterX) * (x - circleCenterX) + (y - circleCenterY) * (y - circleCenterY));
        
        if (distanceToCircleCenter < radius) {
            cout << "The point (" << x << ", " << y << ") in the circle" << endl;
        } else if (distanceToCircleCenter == radius) {
            cout << "The point (" << x << ", " << y << ") at the circle" << endl;
        } else {
            cout << "The point (" << x << ", " << y << ") outside the circle" << endl;
        }
    }
};

int main() {
    Circle circle(5.0, 0.0, 0.0);
    double area = circle.calculateArea();
    double perimeter = circle.calculatePerimeter();
    cout << "Area: " << area << endl;
    cout << "perimeter: " << perimeter << endl;
    double pointX, pointY;
    cout << "entre a point:" << endl;
    cin >> pointX >> pointY;
    circle.checkPoint(pointX, pointY);

    return 0;
}