#include <iostream>
using namespace std;

void SubString(char* &Sub, char* S, int pos, int len) {
    Sub = new char[len + 1]; // allocate memory for the substring
    for (int i = 0; i < len; i++) {
        Sub[i] = S[pos + i - 1]; // copy characters from S to Sub
    }
    Sub[len] = '\0'; // add null terminator to the end of Sub
}

int main() {
    char* S = "This is a program!";
    int pos = 6;
    int len = 2;
    char* Sub;
    SubString(Sub, S, pos, len);
    cout << Sub << endl;
    delete[] Sub; // free memory allocated for Sub
    return 0;
}
