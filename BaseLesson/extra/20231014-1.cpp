#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b){
    int sum = 0;
    int temp;
    if(a>b){
        temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i <= b; i++) {
        if (i % 2 == 1) {
            sum += i;
        }
    }
    cout << sum << endl;
    }
    return 0;
}