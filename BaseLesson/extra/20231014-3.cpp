#include <iostream>
#include <algorithm>
using namespace std;

auto swapValue(int *a, int *b){
    auto temp = *a;
    *a = *b;
    *b = temp;
}

void sortThreeNumbers(int &a, int &b, int &c) {
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a,b,c;
        cin >> a >> b >> c;
        sortThreeNumbers(a,b,c);
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
