#include <iostream>
#include <iomanip>
using namespace std;

template<typename I>
void reverseArray(I array[], int size){
    int left = 0;
    int right = size -1;
    while (left < right) {
        I temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
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
            reverseArray(inputArray,size);
            for(int i=0;i<size;i++){
                cout<<inputArray[i]<<" ";
            }
        }else if(dataType == 2){
            long inputArray[size-1];
            for(int i = 0; i < size; i++){
                cin>>inputArray[i];
            }
            reverseArray(inputArray,size);
            for(int i=0;i<size;i++){
                cout<<inputArray[i]<<" ";
            }
        }else if(dataType == 3){
            double inputArray[size -1];
            for(int i = 0; i < size; i++){
                cin>>inputArray[i];
            }
            reverseArray(inputArray,size);
            for(int i=0;i<size;i++){
                cout<<inputArray[i]<<" ";
            }
        }
    }
    return 0;
}