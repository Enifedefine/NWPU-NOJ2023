#include <iostream>
#include <string>
using namespace std;
long long atoi(string s){
    int sign = 0;
    long long num = 0;
    for (int i = 0 ; s[i] != '\0' ; i ++){
        if (s[i] == ' '){
            continue;
        }
        if (s[i] == '+' && sign == 0){
            sign = 1;
            continue;
        }
        if (s[i] == '-' && sign == 0){
            sign = 2;
            continue;
        }
        if (!(s[i] >= '0' && s[i] <= '9')){
            break;
        }
        if (sign == 0){
            sign = 1;
        }
        num *= 10;
        num += s[i] - '0';
        if (num > 2147483647 && sign == 1){
            num = 2147483647;
            break;
        }
        if (num > 2147483648 && sign == 2){
            num = 2147483648;
            break;
        }
    }
    if (sign == 2){
        num = 0 - num;
    }
    return num;
}
int main(){
    string str;
    getline(cin , str);
    cout << atoi(str) << endl;
    return 0;
}