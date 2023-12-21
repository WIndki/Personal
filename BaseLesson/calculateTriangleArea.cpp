#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Triangle {
    double side1;
    double side2;
    double side3;
};

double calculateArea(Triangle triangle) {
    double p = (triangle.side1 + triangle.side2 + triangle.side3) / 2; 
    double area = sqrt(p * (p - triangle.side1) * (p - triangle.side2) * (p - triangle.side3));
    return area;
}

int main() {
    Triangle triangle;

    while (cin >> triangle.side1 >> triangle.side2 >> triangle.side3) {
        if (triangle.side1 <= 0 || triangle.side2 <= 0 || triangle.side3 <= 0) {
            cout << "not a triangle!" << endl;
        } 
        else if(triangle.side1+triangle.side2 <= triangle.side3 || triangle.side2+triangle.side3 <= triangle.side1 || triangle.side1+triangle.side3 <= triangle.side2){
            cout << "not a triangle!" << endl;
        }
        else {
            double area = calculateArea(triangle);
            cout<<fixed<<setprecision(2);
            cout << area << endl;
        }
    }

    return 0;
}
