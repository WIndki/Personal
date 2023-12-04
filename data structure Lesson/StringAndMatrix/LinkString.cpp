#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char str1[100], str2[100];
       cin>>str1>>str2;
        int len1 = 0;
        while (str1[len1] != '#') {
            len1++;
        }

        int len2 = 0;
        while (str2[len2] != '#') {
            len2++;
        }

        for (int j = len1; j < len1+len2; j++) {
            str1[j] = str2[j-len1];
        }
        str1[len1+len2] = '\0';
        cout <<str1<< endl;
    }

    return 0;
}
