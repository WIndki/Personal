#include <iostream>
using namespace std;

void insertData(int *arr, int size, int data) {
    int *p = arr + size - 1;
    while (p >= arr && *p > data) {
        *(p + 1) = *p; 
        p--;
    }
    *(p + 1) = data;
}


int main() {
    int size;
    while (cin>>size) {
        int *arr = new int[size + 1];
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        int data;
        cin >> data; 
        insertData(arr, size, data); 
        for (int i = 0; i < size + 1; i++) {
            cout << arr[i];
            if (i < size) {
                cout << ",";
            }
        }   
        delete[] arr;   
        cout << endl;
    }
    return 0;
}
