
#include <iostream>
#include <vector>
using namespace std;

// 归并排序
void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] >= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    for (int p = 0; p < temp.size(); p++) {
        nums[left + p] = temp[p];
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
        mergeSort(nums, 0, nums.size() - 1);
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[j];
            if(j<nums.size()-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
