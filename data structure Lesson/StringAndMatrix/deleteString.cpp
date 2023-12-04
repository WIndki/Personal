#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        char str[100];
        cin.getline(str, 100, '#');

        int start, end;
        cin >> start >> end;
        cin.ignore();
        if(start==end){
            for(int j=start-1;j<=strlen(str);j++){
                str[j] = str[j+1];
            }
        }else{
        int len = strlen(str);
        if(end>len){
            end = len;
        }
        for (int j = start - 1; j <= end - 1; j++) {
            str[j] = str[j + end - start + 1];
        }
        str[len - (end - start + 1)] = '\0';
        }
         cout << str << endl;
    }

    return 0;
}
