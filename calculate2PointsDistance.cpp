#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct points{
    float x1;
    float y1;
    float x2;
    float y2;
    float distance;
};

void calculataDistance(points &point){
    point.distance = sqrt(pow(point.x1-point.x2,2)+pow(point.y1-point.y2,2));
}

int main(){
    points point;
    while(cin>>point.x1>>point.y1>>point.x2>>point.y2){
        calculataDistance(point);
        cout<<fixed<<setprecision(2);
        cout<<point.distance<<endl;
    }
    return 0;
}