#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int kval) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == kval) {
            return mid + 1;
        } else if (arr[mid] < kval) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
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
    int result = binarySearch(arr, n, kval);
    cout << result;
    return 0;
}
