#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/*
排序算法：
函数列表
void DirectInsertSort(vector<int> &arr) 直接插入排序
void bubbleSort(vector<int> &arr) 冒泡排序
void selectSort(vector<int> &arr) 选择排序
void shellSort(vector<int> &arr) 希尔排序
void quickSort(vector<int> &arr,int left,int right) 快速排序
void MergeSort(vector<int> &arr,int left,int right) 归并排序
void adjustHeap(vector<int> &arr,int i,int length) 调整堆排序函数
void blockSort(vector<int> &arr) 堆排序
void heapSort(vector<int> &arr) 堆排序
void redixSort(vector<int> &arr) 基数排序
*/
/*
vector类使用说明：
vector<int> arr; 声明一个int型数组
arr.push_back(1); 在数组末尾添加一个元素
arr.pop_back(); 删除数组末尾一个元素
arr.size(); 返回数组元素个数
arr.clear(); 清空数组
arr.empty(); 判断数组是否为空，为空返回true，否则返回false
arr.resize(10); 重新设置数组大小
arr.insert(arr.begin()+1,2); 在数组第二个位置插入元素2
arr.erase(arr.begin()+1); 删除数组第二个元素
arr.erase(arr.begin()+1,arr.begin()+3); 删除数组第二个到第四个元素
arr.front(); 返回数组第一个元素
arr.back(); 返回数组最后一个元素
arr.at(1); 返回数组第二个元素
arr[1]; 返回数组第二个元素
arr1.swap(arr2); 交换arr1和arr2
arr1.assign(arr2.begin(),arr2.end()); 将arr2赋值给arr1
arr1.assign(10,2); 将arr1的大小设置为10，并将每个元素赋值为2
arr1==arr2; 判断arr1和arr2是否相等，相等返回true，否则返回false
*/
void DirectInsertSort(vector<int> &arr) {  // 直接插入排序
  for (int i = 1; i < arr.size(); i++) {   // 从第二个元素开始比较
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp) {  //
      arr[j + 1] = arr[j];             // 将大于temp的元素后移
      j--;
    }
    arr[j + 1] = temp;  // 将temp插入到合适的位置
  }
}

void bubbleSort(vector<int> &arr) {  // 冒泡排序
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void selectSort(vector<int> &arr) {  // 选择排序
  for (int i = 0; i < arr.size(); i++) {
    int minIndex = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

void shellSort(vector<int> &arr) {  // 希尔排序
  for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < arr.size(); i++) {
      int temp = arr[i];
      int j = i - gap;
      while (j >= 0 && arr[j] > temp) {
        arr[j + gap] = arr[j];
        j -= gap;
      }
      arr[j + gap] = temp;
    }
  }
}

void quickSort(vector<int> &arr, int left, int right) {  // 快速排序
  if (left >= right) {
    return;
  }
  int i = left, j = right;
  int temp = arr[left];
  while (i < j) {
    while (i < j && arr[j] >= temp) {
      j--;
    }
    while (i < j && arr[i] <= temp) {
      i++;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[left], arr[i]);
  quickSort(arr, left, i - 1);
  quickSort(arr, i + 1, right);
}

void MergeSort(vector<int> &arr, int left, int right) {  // 归并排序
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  MergeSort(arr, left, mid);
  MergeSort(arr, mid + 1, right);
  vector<int> temp;
  int i = left, j = mid + 1;
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp.push_back(arr[i++]);
    } else {
      temp.push_back(arr[j++]);
    }
  }
  while (i <= mid) {
    temp.push_back(arr[i++]);
  }
  while (j <= right) {
    temp.push_back(arr[j++]);
  }
  for (int i = left; i <= right; i++) {
    arr[i] = temp[i - left];
  }
}

void adjustHeap(vector<int> &arr, int i, int length) {  // 调整堆排序函数
  int temp = arr[i];
  for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
    if (k + 1 < length && arr[k] < arr[k + 1]) {
      k++;
    }
    if (arr[k] > temp) {
      arr[i] = arr[k];
      i = k;
    } else {
      break;
    }
  }
  arr[i] = temp;
}

void heapSort(vector<int> &arr) {  // 堆排序
  for (int i = arr.size() / 2 - 1; i >= 0; i--) {
    adjustHeap(arr, i, arr.size());
  }
  for (int i = arr.size() - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    adjustHeap(arr, 0, i);
  }
}

void blockSort(vector<int> &arr) {  // 桶排序
  int max = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  vector<int> bucket(max + 1, 0);
  for (int i = 0; i < arr.size(); i++) {
    bucket[arr[i]]++;
  }
  int index = 0;
  for (int i = 0; i < bucket.size(); i++) {
    while (bucket[i]--) {
      arr[index++] = i;
    }
  }
}

void redixSort(vector<int> &arr) {  // 基数排序
  int max = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  int maxLength = to_string(max).size();
  vector<vector<int>> bucket(10);
  for (int i = 0; i < maxLength; i++) {
    for (int j = 0; j < arr.size(); j++) {
      int num = (arr[j] / (int)pow(10, i)) % 10;
      bucket[num].push_back(arr[j]);
    }
    int index = 0;
    for (int j = 0; j < bucket.size(); j++) {
      for (int k = 0; k < bucket[j].size(); k++) {
        arr[index++] = bucket[j][k];
      }
      bucket[j].clear();
    }
  }
}

void print(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
