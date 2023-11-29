//二分法查找
#include <iostream>
#include <vector>
using namespace std;

vector<int> createVector(int nums){
    vector<int> v;
    for(int i = 0; i < nums; i++){
        int temp;
        cout<<"data["<<i<<"]=";
        cin >> temp;
        v.push_back(temp);
    }
    return v;
}

void printVector(vector<int> v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void searchTable(vector<int> v){
    int target;
    cout<<"search key=";
    cin >> target;
    int count = 0;
    int low = 0;
    int high = v.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(v[mid] == target){
            cout <<"Find it. data["<< mid <<"]="<<target<< endl;
            return;
        }else if(v[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << "Not Found" << endl;
}

int main(){
    int nums;
    cout<<"total=";
    cin >> nums;
    vector<int> v = createVector(nums);
    printVector(v);
    searchTable(v);
    return 0;
}