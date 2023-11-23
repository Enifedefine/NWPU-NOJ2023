#include <iostream>
#include <string>
using namespace std;
long long meta2dec(string meta){
    long long dec = 0;
    for (int i = 0 ; i < meta.length() ; i ++){
        if (meta[i] >= '0' && meta[i] <= '9'){
            dec *= 36;
            dec += (meta[i] - '0');
        }
        else{
            dec *= 36;
            dec += 10 + (meta[i] - 'A');
        }
    }
    return dec;
}
string dec2meta(long long dec){
    string meta = "";
    for ( ; dec > 0 ; dec /= 36){
        if (dec % 36 <= 9){
            meta = to_string(dec % 36) + meta;
        }
        else{
            meta = char('A' + dec % 36 - 10) + meta;
        }
    }
    if (meta.length() == 0){
        meta = "0";
    }
    return meta;
}
int main(){
    string a , b;
    cin >> a >> b;
    cout << dec2meta(meta2dec(a) + meta2dec(b)) << endl;
    return 0;
}