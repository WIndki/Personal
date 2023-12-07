#include <iostream>
using namespace std;

// 冒泡排序
int bubbleSort(int nums[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
                count++;
            }
        }
    }
    return count;
}

// 直接插入排序
int directInsertSort(int nums[],int size){
    int count=0;
    for(int i=1;i<size;i++){
        int temp=nums[i];
        int j=i-1;
        while(j>=0&&nums[j]>temp){
            nums[j+1]=nums[j];
            j--;
        }
        if(nums[j+1]==temp) continue; // 优化，减少交换次数(不交换相同的元素
            nums[j+1]=temp;
            count++;
    }
    return count;
}

// 选择排序
int selectSort(int nums[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(nums[j]<nums[min]){
                min=j;
            }
        }
        if(min==i) continue; // 优化，减少交换次数(不交换相同的元素
        int temp=nums[i];
        nums[i]=nums[min];
        nums[min]=temp;
        count++;
    }
    return count;
}

// 快速排序并输出次数




void print(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        cout << nums[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

void copy(int nums1[], int nums2[], int size) {
    for (int i = 0; i < size; i++) {
        nums2[i] = nums1[i];
    }
}

int partition(int nums[], int low, int high, int& count) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (nums[j] < pivot) {
            i++;
            if(i==j) continue; // 优化，减少交换次数(不交换相同的元素
            swap(nums[i], nums[j]);
            count++;
        }
    }
    if(i+1==high) return i+1; // 优化，减少交换次数(不交换相同的元素
    swap(nums[i + 1], nums[high]);
    count++;
    return i + 1;
}

void quickSort(int nums[], int low, int high, int& count) {
    if (low < high) {
        int pi = partition(nums, low, high, count);
        quickSort(nums, low, pi - 1, count);
        quickSort(nums, pi + 1, high, count);
    }
}

int main() {
    int size;
    while (cin >> size) {
        int nums1[size];
        int nums2[size];
        int nums3[size];
        int nums4[size];
        for (int j = 0; j < size; j++) {
            cin >> nums1[j];
        }
        for (int j = 0; j < size; j++) {
            nums2[j] = nums1[j];
            nums3[j] = nums1[j];
            nums4[j] = nums1[j];
        }
        cout << "bulleSortTime:" << bubbleSort(nums1, size) << endl;
        print(nums1, size);
        cout << "DirectInsertSortTime:" << directInsertSort(nums2, size) << endl;
        print(nums2, size);
        cout << "SelectSortTime:" << selectSort(nums3, size) << endl;
        print(nums3, size);
        int count = 0;
        quickSort(nums4, 0, size - 1, count);
        cout << "quickSortTIme:" << count << endl;
        print(nums4, size);
    }
    return 0;
}