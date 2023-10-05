#include <iostream>

using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    Box(double len, double wid, double hei) {
        length = len;
        width = wid;
        height = hei;
    }

    double calculateSurfaceArea() {
        double surfaceArea = 2 * (length * width + length * height + width * height);
        return surfaceArea;
    }

    double calculateVolume() {
        double volume = length * width * height;
        return volume;
    }
};

int main() {
    double edge1,edge2,edge3;
    cin>>edge1>>edge2>>edge3;
    Box box(edge1, edge2, edge3);
    double surfaceArea = box.calculateSurfaceArea();
    double volume = box.calculateVolume();
    cout << "surfaceArea=" << surfaceArea << endl;
    cout << "Volume=" << volume << endl;

    return 0;
}