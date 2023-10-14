#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        int leghth = abs(a-c);
        int wide = abs(b-d);
        int area = leghth*wide;
        int perimeter = 2*(leghth+wide);
        cout<<"area:"<<area<<" "<<"perim:"<<perimeter<<endl;
    }
}