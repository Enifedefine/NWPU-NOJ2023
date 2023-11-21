#include <iostream>
#include <string>
using namespace std;
bool str_endswith(string str, string suffix){
    for (int i = str.length() - 1 ; i >= 0 ; i --){
        if (str.length() - i + 1 > suffix.length()){
            break;
        }
        if (str[i] != suffix[str.length() - i]){
            return false;
        }
    }
    return true;
}
int main() {
    string str , suffix;
    getline(cin , str);
    getline(cin , suffix);
    cout << (str_endswith(str , suffix)?"Yes":"No") << endl;
    return 0;
}
