#include <iostream>
#include <string>
using namespace std;
string str_swapcase(string str){
    for (int i = 0 ; str[i] != '\0' ; i ++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = 'A' + str[i] - 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = 'a' + str[i] - 'A';
        }
    }
    return str;
}
int main(){
    string str;
    getline(cin , str);
    cout << str_swapcase(str);
    return 0;
}