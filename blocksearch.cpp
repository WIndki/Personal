#include <iostream>
#include <vector>
using namespace std;

struct block{
    int key;
    int start;
    int end;
};

int findMax(vector<int> arr,int start,int end){
    int max = arr[start];
    int index = start;
    for(int i=start;i<=end;i++){
        if(arr[i]>max){
            max = arr[i];
            index = i;
        }
    }
    return index;
}

int blockSearch(vector<int> arr,vector<block> blocks,int kval){
    int Index = -1;
    for(int i=0;i<blocks.size();i++){
        if(kval<=blocks[i].key){
            Index = i;
            break;
        }
    }

    if(Index!=-1){
        for(int i=blocks[Index].start;i<=blocks[Index].end;i++){
            if(arr[i]==kval){
                return i+1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<block> blocks(3);
    blocks[0].key = arr[findMax(arr,0,(n/3)-1)];
    blocks[0].start = 0;
    blocks[0].end = (n/3)-1;
    blocks[1].key = arr[findMax(arr,(n/3),2*(n/3)-1)];
    blocks[1].start = n/3;
    blocks[1].end = 2*(n/3)-1;
    blocks[2].key = arr[findMax(arr,2*(n/3),n-1)];
    blocks[2].start = 2*(n/3);
    blocks[2].end = n-1;
    int kval;
    cin>>kval;
    int index = blockSearch(arr,blocks,kval);
    if(index!=0){
        cout<<index<<endl;
    }
    return 0;
}