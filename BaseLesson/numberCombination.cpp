#include <iostream>

using namespace std;

int main() {
    int n, start;
    while (cin >> n >> start) {
        int count = 0; 
        for (int i = start; i <= start + n - 1; i++) {
            for (int j = start; j <= start + n - 1; j++) {
                for (int k = start; k <= start + n - 1; k++) {
                    if (i != j && j != k && i != k) {
                        cout.width(4);
                        cout << i * 100 + j * 10 + k;
                        count++;
                        if (count % 10 == 0) {
                            cout << endl;
                        }
                    }
                }
            }
        }
        if(count%10 != 0){
            cout <<endl;
        }
        cout <<"Total of "<< count <<" numbers."<< endl;
    }

    return 0;
}
