#include <iostream>
#include <string>
using namespace std;
string str_removeprefix(string str, string prefix){
    for (int i = 0 ; prefix[i] != '\0' ; i ++){
        if (prefix[i] != str[i]){
            break;
        }
        if (i == prefix.length() - 1){
            str.erase(0 , prefix.length());
            i = -1;
        }
    }
    return str;
}
string str_removesuffix(string str, string suffix){
    int i = str.length() - 1;
    int j = suffix.length() - 1;
    while (true){
        if (suffix[j] != str[i]){
            break;
        }
        if (j == 0){
            str.erase(i , suffix.length());
            i = str.length() - 1;
            j = suffix.length() - 1;
        }
        i --;
        j --;
    }
    return str;
}
int main(){
    string str , words;
    getline(cin , str);
    getline(cin , words);
    cout << str_removeprefix(str , words) << endl;
    cout << str_removesuffix(str , words) << endl;
    return 0;
}