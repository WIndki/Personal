#include <iostream>
using namespace std;

bool isEquation(int data[10]){
    int first = data[0];
    for(int i = 1; i < 10; i++){
        if(data[i] != first && data[i] != 0){
            return 0;
        }
    }
    return 1;
}

void giveCandy(int *data){
    int value=0;
    int temp[11]={0};
    for(int i =0;i<10;i++){
        temp[i]=data[i]/2;
        data[i]=data[i]/2;
    }
    for(int i =0;i<9;i++){
        data[i+1]+=temp[i];
    }
    data[0]+=temp[9];
    for(int i =0;i<9;i++){
        if(data[i]%2!=0){
            data[i]++;
        }
    }
}

int main(){
    int data[10] = {0};
    int count = 0;
    for(int i=0;i<10;i++){
        cin>>data[i];
    }
    while(isEquation(data)==0){
        giveCandy(data);
        count++;
    }
    cout<<count<<" "<<data[0];
}