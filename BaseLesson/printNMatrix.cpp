#include <iostream>
#include <iomanip> 
using namespace std;
void printMatrix(int n) {
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= n; j++) {
            cout.width(3);
            cout << to_string(min(i, j));
        }
        cout << endl;
    }
}

int main() {
    int n;
    while (cin >> n) {
        printMatrix(n);
    }
    return 0;
}
