#include <iostream>
#include <cstring>
using namespace std;

int strReplaceAll(char * str, char * sub, char * replace){
    int len = strlen(str);
    int subLen = strlen(sub);
    int replaceLen = strlen(replace);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (strncmp(str + i, sub, subLen) == 0) {
            count++;
            i += subLen - 1;
        }
    }
    int newLen = len + count * (replaceLen - subLen);
    if (newLen >= 500) {
        return -1; // 替换后的字符串超过了最大长度
    }
    char newStr[500];
    int newIndex = 0;
    for (int i = 0; i < len; i++) {
        if (strncmp(str + i, sub, subLen) == 0) {
            strncpy(newStr + newIndex, replace, replaceLen);
            newIndex += replaceLen;
            i += subLen - 1;
        } else {
            newStr[newIndex++] = str[i];
        }
    }
    newStr[newIndex] = '\0';
    strcpy(str, newStr);
    return 0;
}

void remove(char *s,int start,int end){
    int len = strlen(s);
    for(int i=start-1;i<len;i++){
        s[i] = s[i+end-start+1];
    }
}

void insert(char *s,int start,char *t){
    int len = strlen(s);
    int len1 = strlen(t);
    s[len+len1] = '\0';//s[len-1] = '\0' [
    for(int i=len-1;i>=start;i--){
        s[i+len1] = s[i];
    }
    for(int i=0;i<len1;i++){
        s[start+i] = t[i];
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        char str[500];
        char sub[500];
        char replace[500];
        cin >> str >> sub >> replace;
        int len = strlen(str);
        int len1 = strlen(sub);
        int len2 = strlen(replace);
        str[len-1] = '\0';
        sub[len1-1] = '\0';
        replace[len2-1] = '\0';
        int start,end;
        cin>>start>>end;
        if(start>strlen(str)){
            start = strlen(str)-1;
            cout<<str<<endl;
            return 0;
        } 
        if(end>strlen(str)){
            end = strlen(str);
        }
        char str1[end-start+100];
        for(int i=start-1;i<end;i++){
            str1[i-start+1] = str[i];
        }
        str1[end-start+1] = '\0';
        remove(str,start,end);
        strReplaceAll(str1, sub, replace);
        insert(str,start-1,str1);
        cout<<str<<endl;
    }
    return 0;
}
