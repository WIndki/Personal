#include <iostream>
#include <algorithm>
using namespace std;
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

int main()
{
    int str1[] = {1,2,3,4};
    int str2[] = {1,2,3,4};
    for(int i=0;i<4;i++){
    cout<<str1[i];
    }
    cout<<endl;
    for(int i=0;i<4;i++){
    cout<<str2[i];
    }
    cout<<endl;
    while(mynext_permutation(str1,str1+3))
    {
        next_permutation(str2,str2+3);
        for(int i=0;i<4;i++){
            cout<<str1[i];
        }
        cout<<endl;
        for(int i=0;i<4;i++){
            cout<<str2[i];
        }
        cout<<endl;
    }
    return 0;
}