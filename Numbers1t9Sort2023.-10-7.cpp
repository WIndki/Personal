#include <iostream>
#include <algorithm>
using namespace std;

bool isExpressionValid(int* digits) {
    int num1 = digits[0] * 100 + digits[1] * 10 + digits[2];
    int num2 = digits[3] * 100 + digits[4] * 10 + digits[5];
    int num3 = digits[6] * 100 + digits[7] * 10 + digits[8];
    return (num1 + num2 == num3);
}

bool isAppeared(int *arr, int num2, int count){
    for(int i=0;i<count;i++){
        if(arr[i]==num2){
            return 1;
        }
    }
    return 0;
}

void generateAndOutputExpressions() {
    int digits[9];
    for(int i=1;i<=9;i++){
        digits[i-1]=i;
    }
    int count = 0;
    int count1 = 0;
    int *arr = new int[count+1]();
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
    }while(next_permutation(digits,digits+9));
    cout <<"Total of " << count << " Expressions."<<endl;
    delete[] arr;
}

int main() {
    generateAndOutputExpressions();
    return 0;
}
