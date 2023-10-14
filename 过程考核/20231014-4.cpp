#include <iostream>
using namespace std;

bool isPrimenumber(int number){
    if (number < 2)return false;
	for (int i = 2; i < number; i++)
		if (number % i == 0)
			return false;
	return true;
}

int main(){
    int a,b;
    int count = 0;
    while (cin>>a>>b)
    {
        int temp;
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
        for(int i=a;i<=b;i++){
            if(isPrimenumber(i)){
                cout.width(4);
                cout<<i;
                count++;
                if(count%10==0)cout<<endl;
            }
        }
        count = 0;
        cout<<endl;
    }
    

}

