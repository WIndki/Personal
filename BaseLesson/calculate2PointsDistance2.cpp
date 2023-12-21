#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class points{
    public:
    float x;
    float y;
    float operator-(const points& B) const {//重载-运算符
        float distance = sqrt(pow(x-B.x,2)+pow(y-B.y,2));
        return distance;
    }
};

// float calculataDistance(points point1, points point2){
//     float distance = sqrt(pow(point1.x-point2.x,2)+pow(point1.y-point2.y,2));
//     return distance;
// }

int main(){
    points point1, point2;
    while(cin>>point1.x>>point1.y>>point2.x>>point2.y){
        cout<<fixed<<setprecision(2);
        cout<<point1 - point2<<endl;
    }
    return 0;
}