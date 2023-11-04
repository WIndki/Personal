#include <iostream>
#include <iomanip>
using namespace std;

class straight_cylinder
{
private:
    double area;
    double height;
    double volume;
public:
    straight_cylinder(double a=0, double h)
    {
        area = a;
        height = h;
        volume = a*h;
    }
    double get_volume()
    {
        return volume;
    }
};

int main(){
    int op;
    while(cin>>op){
        if(op==0){
            double radius;
            double h=0;
            cin>>radius>>h;
            double radius_area = 3.141592653589793238*radius*radius;
            straight_cylinder sc(radius_area, h);
            cout<<fixed<<setprecision(2)<<sc.get_volume()<<endl;
        }
        else if(op==1){
            double edge1,edge2,edge3;
            double h=0;
            cin>>edge1>>edge2>>edge3>>h;
            double p = (edge1+edge2+edge3) / 2; 
            double area = sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
            straight_cylinder sc2(area, h);
            cout<<fixed<<setprecision(2)<<sc2.get_volume()<<endl;
        }
        else if(op==2){
            double length, width;
            double h=0;
            cin>>length>>width>>h;
            double area2 = length*width;
            straight_cylinder sc3(area2, h);
            cout<<fixed<<setprecision(2)<<sc3.get_volume()<<endl;
        }
    }
    return 0;
}