#include <iostream>
#include <iomanip>
using namespace std;

auto reverseArray(auto array[], int size, auto temp){
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    return array;
}
void reverseIntArray(int array[], int size) {
    int left = 0;  
    int right = size - 1;  
    int temp;
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    for (int i = 0; i < size; i++) {
    cout << array[i];
    if (i < size -1){
        cout << ",";
    }
    }
    cout << endl;
}

void reverseDoubleArray(double array[], int size) {
    int left = 0; 
    int right = size - 1;
    double temp;
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    for (int i = 0; i < size; i++) {
    cout<<fixed<<setprecision(2);
    cout << array[i];
    if (i < size -1){
        cout << ",";
    }
    }
    cout << endl;
}

void reverseLongArray(long array[], int size) {
    int left = 0; 
    int right = size - 1;
    long temp;
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    for (int i = 0; i < size; i++) {
    cout << array[i];
    if (i < size -1){
        cout << ",";
    }
    }
    cout << endl;
}

int main(){
    int dataType;
    int size;
    while(cin >> dataType >> size){
        if(dataType == 1){
            int inputArray[size-1];
            for(int i = 0; i < size; i++){
                cin>>inputArray[i];
            }
            reverseIntArray(inputArray,size);
        }else if(dataType == 2){
            long inputArray[size-1];
            for(int i = 0; i < size; i++){
                cin>>inputArray[i];
            }
            reverseLongArray(inputArray,size);
        }else if(dataType == 3){
            double inputArray[size -1];
            for(int i = 0; i < size; i++){
                cin>>inputArray[i];
            }
            reverseDoubleArray(inputArray,size);
        }
    }
    return 0;
}