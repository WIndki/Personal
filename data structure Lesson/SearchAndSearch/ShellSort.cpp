#include <iostream>
#include <vector>
using namespace std;

// 希尔排序
void shellSort(vector<int>& nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = nums[i];
            int j = i;
            while (j >= gap && nums[j - gap] < temp) {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = temp;
        }
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
        shellSort(nums);
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[j];
            if(j<nums.size()-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
