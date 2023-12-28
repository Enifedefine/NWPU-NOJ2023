#include <iostream>
#include <string>
using namespace std;
char l[255];
char add(char c , int x){
    x = x % 26;
    if (c + x > 'z'){
        return (c + x - 26);
    }
    if (c + x < 'a'){
        return (c + x + 26);
    }
    return (c + x);
}
int main(){
    string str;
    int x;
    cin >> str >> x;
    for (int i = 0 ; i < str.length() ; i ++){
        l[str[i]] ++;
    }
    for (int i = 0 ; i < str.length() ; i ++){
        if (l[str[i]] % 2 == 0){
            str[i] = add(str[i] , x);
        }
        else{
            str[i] = add(str[i] , 0 - x);
        }
    }
    cout << str << endl;
    return 0;
}