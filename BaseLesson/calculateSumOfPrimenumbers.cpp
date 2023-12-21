#include <iostream>
using namespace std;

bool isPrimenumber(int number){
    if (number < 2)return false;//不是素数
	for (int i = 2; i < number; i++)
		if (number % i == 0)//能被其他数整除
			return false;
	return true;
}

int calculateSumOfPrimenumbers(int start,int end){
    int sum = 0;
    for(int i=start;i<=end;i++){
        if(isPrimenumber(i)){
            sum = sum + i;
        }
    }
    return sum;
}

int main(){
    int input1,input2;
    while(cin>>input1>>input2){
        int start, end;
        if(input1>input2){
            start = input2;
            end = input1;
        }
        else{
            start = input1;
            end = input2;
        }
        int sum = calculateSumOfPrimenumbers(start,end);
        cout<<sum<<endl;
    }
    return 0;
}