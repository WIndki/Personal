#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    while(cin >> n){
    for (int i = 1; i <= n; i++) {
        if(i%2 == 0){
            for(int m = 1;m<=n-i;m++)cout << " ";
            for(int m = 1;m<=i;m++)cout << "*";
        }
        else{
            for(int m = 1;m<=n-i;m++)cout << " ";
            for(int m = 1;m<=i;m++)cout << "$";
        }
        cout << endl;
    }
    }
    return 0;
}
