#include <iostream>
#include <string>
using namespace std;
string sarr[25];
int str_split(string str, string sep){
    int i = 0;
    int num = 0;
    for (int j = 0 ; str[j] != '\0' ; j ++){
        for (int k = j  ; ; k ++){
            if (str[k] != sep[k - j]){
                break;
            }
            if (k - j + 1 == sep.length()){
                sarr[num] = str.substr(i , j - i);
                num ++;
                i = k + 1;
                j = k;
                break;
            }

        }
    }
    return num;
}
int main(){
    string str , sep;
    getline(cin , str);
    getline(cin , sep);
    str = str + sep;
    int num = str_split(str , sep);
    for (int i = 0 ; i < num ; i ++){
        cout << sarr[i] << endl;
    }
    return 0;
}