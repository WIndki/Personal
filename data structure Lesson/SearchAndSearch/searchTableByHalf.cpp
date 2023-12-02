//二分法查找
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int data;
    int pos;
};
vector<node> createVector(int nums){
    vector<node> v;
    for(int i = 0; i < nums; i++){
        node temp;
        cout<<"data["<<i<<"]=";
        cin >> temp.data;
        temp.pos = i;
        v.push_back(temp);
    }
    return v;
}

void printVector(vector<node> v){
    for(vector<node>::iterator it = v.begin(); it != v.end(); it++){
        cout << it->data << " ";
    }
    cout << endl;
}

void searchTable(vector<node> l){
    int target;
    cout<<"search key=";
    cin >> target;
    for(int i =0;i<l.size();i++){
        if(l[i].data == target){
            cout <<"Find it. data["<< l[i].pos <<"]="<<target<< endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}
bool compare(node a, node b){
    return a.data < b.data;
}
void HalfsearchTable(vector<node> v){
    // for(int i = 0; i < v.size(); i++){
    //     for(int j = i + 1; j < v.size(); j++){
    //         if(v[i].data > v[j].data){
    //             node temp = v[i];
    //             v[i] = v[j];
    //             v[j] = temp;
    //         }
    //     }
    // }
    sort(v.begin(), v.end(), compare);
    int target;
    cout<<"search key=";
    cin >> target;
    int count = 0;
    int low = 0;
    int high = v.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(v[mid].data == target){
            cout <<"Halfsearch Find it. data["<< v[mid].pos <<"]="<<target<< endl;
            return;
        }else if(v[mid].data > target){
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
    vector<node> v = createVector(nums);
    printVector(v);
    searchTable(v);
    HalfsearchTable(v);
    return 0;
}