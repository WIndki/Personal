#include <iostream>
#include <algorithm>
using namespace std;

bool isExpressionValid(int* digits) {
    int num1 = digits[0] * 100 + digits[1] * 10 + digits[2];
    int num2 = digits[3] * 100 + digits[4] * 10 + digits[5];
    int num3 = digits[6] * 100 + digits[7] * 10 + digits[8];
    return (num1 + num2 == num3);
}

// bool isAppeared(int *arr, int num2, int count){
//     for(int i=0;i<count;i++){
//         if(arr[i]==num2){
//             return 1;
//         }
//     }
//     return 0;
// }

bool isAppeared(int *arr, int num2, int count){
    int low = 0;
    int high = count-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==num2){
            return 1;
        }else if(arr[mid]>num2){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return 0;
}

template<typename T>//模板是创建泛型类或函数的蓝图或公式。
bool mynext_permutation(T *start, T *end) { //[start,end)
	T *cur = end - 1, *pre = cur - 1; //pre指向partitionNumber 
	while (cur > start && *pre >= *cur) 
		--cur, --pre; //从右到左进行扫描，发现第一个违背非递减趋势的数字
	if (cur <= start) return false; //整个排列逆序, 不存在更大的排列 
	//从右到左进行扫描，发现第一个比partitionNumber大的数
	for (cur = end - 1; *cur <= *pre; --cur); //cur指向changeNumber  
	swap(*pre, *cur);
	reverse(pre + 1, end); //将尾部的逆序变成正序 
	return true; 
}


void generateAndOutputExpressions() {
    int digits[9];
    for(int i=1;i<=9;i++){
        digits[i-1]=i;
    }
    int count = 0;
    int count1 = 0;
    int *arr = new int[200]();
    do{
        if (isExpressionValid(digits)) {
            int num1 = digits[0] * 100 + digits[1] * 10 + digits[2];
            if(!isAppeared(arr,num1,count)){
                arr[count1] = num1;
                count1++;
            }
            int num2 = digits[3] * 100 + digits[4] * 10 + digits[5];
            int num3 = digits[6] * 100 + digits[7] * 10 + digits[8];
            if(isAppeared(arr,num2,count)){
                continue;
            }
            cout << num1 << "+" << num2 << "=" << num3;
            count++;
            if (count % 4 == 0) {
                cout <<endl;
            }else{
                cout<< " ";
            }
            
    }
    }while(mynext_permutation(digits,digits+9));
    cout <<"Total of " << count << " Expressions."<<endl;
    delete[] arr;
}

int main() {
    generateAndOutputExpressions();
    return 0;
}
