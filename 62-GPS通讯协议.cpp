#include <iostream>
#include <string>
using namespace std;
bool f(){
    string str;
    cin >> str;
    if (str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str.length() == 3){
        return false;
    }
    if (str[1] != 'G' || str[2] != 'P' || str[3] != 'R' || str[4] != 'M' || str[5] != 'C'){
        return true;
    }
    int ans = str[1];
    for (int i = 2 ; i < str.length() ; i ++){
        if (str[i] == '*'){
            int check = 0;
            for (int j = i + 1 ; j < str.length() ; j ++){
                if (str[j] >= 'A' && str[j] <= 'F'){
                    check *= 16;
                    check += str[j] - 'A' + 10;
                }
                else{
                    check *= 16;
                    check += str[j] - '0';
                }
                check %= 65536;
            }
            if (check != ans){
                cout << "error" << endl;
                return true;
            }
            break;
        }
        if (str[i] == ','){
            continue;
        }
        ans = (ans^str[i]) % 65536;
    }
    cout << ((str[8] - '0') + ((str[7] - '0') * 10) + 8) % 24 << ":";
    cout << (str[10] - '0') + ((str[9] - '0') * 10) << ":";
    cout << (str[12] - '0') + ((str[11] - '0') * 10) << endl;
    return true;
}
int main(){
    while(f()){
        
    }
    return 0;
}