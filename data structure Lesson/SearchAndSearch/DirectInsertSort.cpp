#include <iostream>
#include <vector>
using namespace std;

// 直接插入排序
void directInsertSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] < temp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> nums;
        int num;
        while (cin >> num && num != -1) {
            nums.push_back(num);
        }
        directInsertSort(nums);
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[j];
            if(j<nums.size()-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
