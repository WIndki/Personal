#include <iostream>
#include <vector>
using namespace std;
/*
查找表类
函数列表
InorderSearch(vector<int> arr, int n, int key) 顺序查找，返回元素在原数组中的位置
HalfSearch(vector<int> arr, int key) 二分查找，返回元素在原数组中的位置
*/

int InorderSearch(vector<int> arr, int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int HalfSearch(vector<int> arr, int key) {  // 二分查找,前提是数组有序
  int left = 0, right = arr.size() - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      right = mid - 1;
    } else if (arr[mid] < key) {
      left = mid + 1;
    }
  }
  return -1;
}
//查找表完