//顺序查找
#include <iostream>
#include <list>
using namespace std;

list<int> createList(int nums){
    list<int> l;
    for(int i = 0; i < nums; i++){
        int temp;
        cout<<"data["<<i<<"]=";
        cin >> temp;
        l.push_back(temp);
    }
    return l;
}

void printList(list<int> l){
    for(list<int>::iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void searchTable(list<int> l){
    int target;
    cout<<"search key=";
    cin >> target;
    int count = 0;
    for(list<int>::iterator it = l.begin(); it != l.end(); it++){
        if(*it == target){
            cout <<"Find it. data["<< count <<"]="<<target<< endl;
            return;
        }
        count++;
    }
    cout << "Not Found" << endl;
}

int main(){
    int nums;
    cout<<"total=";
    cin >> nums;
    list<int> l = createList(nums);
    printList(l);
    searchTable(l);
    return 0;
}