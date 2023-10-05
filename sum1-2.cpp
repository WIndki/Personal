#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int calculateValue(int a, int n) {
    int sum = 0;
    int term = a;
    int newTerm = 0;

    for (int i = 0; i < n; i++) {
        newTerm = term * pow(10, i) + newTerm;
        sum = newTerm + sum;
    }
    
    return sum;
}

string outExpressionString(int a, int n) {
    string Expression;
    int term = a;
    
    for(int i = 0 ; i < n ; i++){
        Expression = Expression + to_string(term);
        if(i < n-1){
            Expression = Expression + "+";
        }
        term = term*10 + a; 
    }
    
    return Expression;
}

int main (){
    int a;
    int n;
    while(cin>>a>>n){
        if(a < 10){
            int Value = calculateValue(a,n);
            string Expression = outExpressionString(a,n);
            cout<<Expression<<"="<<Value<<endl;
        }
        else{
            cout<<"illegal input"<<endl;
        }
    }
    return 0 ;
}