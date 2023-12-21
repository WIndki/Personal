#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    cout << "entre 2 number:" << endl;
    cin >> num1 >> num2;
    int greatestCommonDivisor = gcd(num1, num2);
    int leastCommonMultiple = lcm(num1, num2);
    cout << "The greatestCommonDiviosr:" << greatestCommonDivisor << endl;
    cout << "The leastCommonMultiple:" << leastCommonMultiple << endl;

    return 0;
}