#include <iostream>
using namespace std;

int search(int arr[], int n, int kval) {
    // 设置哨兵
    arr[n] = kval;
    int i = 0;
    while (arr[i] != kval) {
        i++;
    }
    if (i < n) {
        return i + 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int kval;
    cin >> kval;
    int result = search(arr, n, kval);
    cout << result;
    return 0;
}
