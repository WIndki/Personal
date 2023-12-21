#include <iostream>
using namespace std;

void insertElement(int inputArray[], int &count, int insertElementPosition, int element){
    for( int i = count; i > insertElementPosition ; i-- ){
        inputArray[i] = inputArray[i-1];
    }
    inputArray[insertElementPosition] = element;
    count++;
}

void deleteElement(int inputArray[], int &count, int deleteElementPosition){
    for( int i = deleteElementPosition; i < count-1; i++ ){
        inputArray[i] = inputArray[i+1];
    }
    count--;
}

void printArray(int inputArray[], int count){
    for(int i = 0 ; i < count; i++){
        cout<<inputArray[i];
        if(i < count - 1 ){
            cout<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int count;
    int operationType;
    while(cin>>count){
        int inputArray[count-1];
        for(int i = 0; i < count; i++){
            cin>>inputArray[i];
            }
        cin>>operationType;
        if(operationType ==1){
            int insertElementPosition;
            int element;
            cin>>insertElementPosition>>element;
            insertElement(inputArray,count,insertElementPosition,element);
        }else if(operationType == 2){
            int deleteElementPostion;
            cin>>deleteElementPostion;
            deleteElement(inputArray,count,deleteElementPostion);
        }
        printArray(inputArray,count);
    }
    return 0;
}