#include <iostream>
#include <iomanip>
using namespace std;

auto swapValue(auto *a, auto *b){
    auto temp = *a;
    *a = *b;
    *b = temp;
}

void sortThreeNumbers(auto *a, auto *b, auto *c) {
    if (*a > *b) {
        swap(a, b);
    }
    if (*b > *c) {
        swap(b, c);
    }
    if (*a > *b) {
        swap(a, b);
    }
    cout<<*a<<","<<*b<<","<<*c<<endl;
}

int main(){
    int datatype;
    while(cin>>datatype){
        if(datatype == 1){
            int a,b,c;
            int *ptr_a,*ptr_b,*ptr_c;
            cin>>a>>b>>c;
            ptr_a = &a;
            ptr_b = &b;
            ptr_c = &c;
            sortThreeNumbers(ptr_a,ptr_b,ptr_c);
        }else if(datatype ==2){
            long a,b,c;
            long *ptr_a,*ptr_b,*ptr_c;
            cin>>a>>b>>c;
            ptr_a = &a;
            ptr_b = &b;
            ptr_c = &c;
            sortThreeNumbers(ptr_a,ptr_b,ptr_c);
        }else if(datatype ==3){
            double a,b,c;
            double *ptr_a,*ptr_b,*ptr_c;
            cin>>a>>b>>c;
            ptr_a = &a;
            ptr_b = &b;
            ptr_c = &c;
            cout<<fixed<<setprecision(2);
            sortThreeNumbers(ptr_a,ptr_b,ptr_c); 
        }
    }
    return 0;
}