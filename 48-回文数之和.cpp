#include <iostream>
using namespace std;
bool str_is_pali(string x){
    for (int i = 0 ; i <= x.size()/2 ; i ++){
        if (x[i] != x[x.size() - i - 1]){
            return false;
        }
    }
    return true;
}
string trans(int x , int k){
    string str = "";
    while (x > 0){
        str = to_string(x % k) + str;
        x /= k;
    }
    return str;
}
bool is_pali(int x , int k){
    return str_is_pali(trans(x , k));
}

int main() {
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1 ; i < n ; i ++){
        if (is_pali(i , 10) && is_pali(i , k)){
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
