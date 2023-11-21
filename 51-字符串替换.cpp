#include <iostream>
#include <string>
using namespace std;

void str_replace(string &str, string olds, string news){
    for (int i = 0 ; str[i] != '\0' ; i ++){
        for (int j = i ; str[j] != '\0' ; j ++){
            if (str[j] != olds[j - i]){
                break;
            }
            if (j - i + 1 == olds.length()){
                str = str.replace(i , j - i + 1 , news);
                i = i + news.length() - 1;
                break;
            }
        }
    }
}

int main() {
    string str , olds , news;
    getline(cin , str);
    getline(cin , olds);
    getline(cin , news);
    str_replace(str,olds,news);
    cout << str << endl;
    return 0;
}
