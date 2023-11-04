#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

template<class T>
class complex_numbers
{
private:
    T real;
    T imaginary;
public:
    complex_numbers(T r = 0, T i = 0)
    {
        real = r;
        imaginary = i;
    }
    ~complex_numbers()
    {
        real = 0;
        imaginary = 0;
    }
    complex_numbers operator+(complex_numbers const &obj)
    {
        complex_numbers res;
        res.real = real + obj.real;
        res.imaginary = imaginary + obj.imaginary;
        return res;
    }
    complex_numbers operator-(complex_numbers const &obj)
    {
        complex_numbers res;
        res.real = real - obj.real;
        res.imaginary = imaginary - obj.imaginary;
        return res;
    }
    complex_numbers operator*(complex_numbers const &obj)
    {
        complex_numbers res;
        res.real = real * obj.real - imaginary * obj.imaginary;
        res.imaginary = real * obj.imaginary + imaginary * obj.real;
        return res;
    }
    complex_numbers operator/(complex_numbers const &obj)
    {
        complex_numbers res;
        res.real = (real * obj.real + imaginary * obj.imaginary) / (obj.real * obj.real + obj.imaginary * obj.imaginary);
        res.imaginary = (imaginary * obj.real - real * obj.imaginary) / (obj.real * obj.real + obj.imaginary * obj.imaginary);
        return res;
    }
    void print()
    {
        cout<<fixed<<setprecision(2);
        cout <<"("<<real <<","<<imaginary <<"i)"<< endl;
    }
};

int main()
{
    int n;
    while (cin >> n)
    {
        int op=0;
        complex_numbers<float> c;
        for(int count=0;count<n;count++)
        {
            float r,i;
            cin >> r >> i;
            complex_numbers<float> a(r,i);
            if(count==0)c=a;
            if(op==1){
                c=c+a;
            }
            else if(op==2){
                c=c-a;
            }
            else if(op==3){
                c=c*a;
            }
            else if(op==4){
                c=c/a;
            }
            if(count<n-1)cin>>op;
        }
        c.print();
    }
    return 0;
}

