#include <iostream>
#include <string>
using namespace std;
bool dict[257];
string str_lstrip(string str){
    for (int i = 0 ; str[i] != 0 ; i ++){
        if (dict[str[i]]){
            str.erase(i , 1);
            i --;
        }
        else{
            return str;
        }
    }
    return str;
}
string str_rstrip(string str){
    for (int i = str.length() - 1 ; i >= 0 ; i --){
        if (dict[str[i]]){
            str.erase(i , 1);
        }
        else{
            return str;
        }
    }
    return str;
}
string str_strip(string str){
    str = str_lstrip(str);
    str = str_rstrip(str);
    return str;
}
int main() {
    string str , chars;
    getline(cin , str);
    getline(cin , chars);
    for (int i = 0 ; chars[i] != '\0' ; i ++){
        dict[chars[i]] = true;
    }
    cout << str_lstrip(str) << endl;
    cout << str_rstrip(str) << endl;
    cout << str_strip(str) << endl;
    return 0;
}
