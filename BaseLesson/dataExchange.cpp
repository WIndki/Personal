#include <iostream>
using namespace std;

struct pointer
{
    int *min_pointer;
    int *max_pointer;
};

void swapValue(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

pointer SearchMaxAndMinValue(int *arr,int size){
   struct pointer ValuePointer;
   ValuePointer.min_pointer = arr; 
   ValuePointer.max_pointer = arr;
    for(int i = 1;i < size;i++){
        if(*ValuePointer.min_pointer>*(arr+i)){
            ValuePointer.min_pointer = arr+i;
        }
        if(*ValuePointer.max_pointer<*(arr+i)){
            ValuePointer.max_pointer = arr+i;
        }
    }
    return ValuePointer;
}

int main(){
    int size;
    while(cin>>size){
        int *arr = new int[size];
        for(int i = 0;i<size;i++){
            cin>>*(arr+i);
        }   
        pointer ValuePtr = SearchMaxAndMinValue(arr,size);
        swapValue(arr,ValuePtr.min_pointer);
        swapValue(arr+size-1,ValuePtr.max_pointer);
        for (int i = 0; i < size; i++) {
            cout.width(6);
            cout << *(arr + i);
        }
        
        cout << endl;
        
        delete [] arr;
    }
    return 0;
}
