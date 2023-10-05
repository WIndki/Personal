#include <iostream>
#include <iomanip>
using namespace std;

auto reverseArray(auto array[], int size, auto temp){
    int left = 0;
    int right = size -1;
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    return array;
}
void printArray(auto p,int size){
    for (int i = 0; i < size; i++) {
        cout << *p;
        if (i < size -1){
            cout << ",";
        }
        p++;
    }
    cout << endl;
}
void reverseIntArray(int array[], int size) {
    int temp;
    int *p;
    p = reverseArray(array,size,temp);
    printArray(p,size);
}

void reverseDoubleArray(double array[], int size) {
    double temp;
    double *p;
    p = reverseArray(array,size,temp);
    cout<<fixed<<setprecision(2);
    printArray(p,size);
}

void reverseLongArray(long array[], int size) {
    long temp;
    long *p;
    p = reverseArray(array,size,temp);
    printArray(p,size);
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