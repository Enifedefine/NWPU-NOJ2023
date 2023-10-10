#include <iostream>
#include <string>
using namespace std;
string f(int n){
    string ans = "";
    for (int i = 0 ; n > 0 ; i ++){
        if (n & 1){
            if (i == 1){
                ans = "+2" + ans;
            }
            else{
                ans = ")" + ans;
                ans = to_string(i) + ans;
                ans = "+2(" + ans;
            }         
        } 
        n = n >> 1;
    }
    if (ans[0] == '+'){
        ans.erase(0,1);
    }
    return ans;
}
int main() {
    string n;
    cin >> n;
    // 
    for (int i = 0 ; n[i] != '\0' ; i ++){
        //cout << n << endl;
        if (n[i] >= '0' && n[i] <= '9'){
            int num = 0;
            int j;
            for (j = i ; (n[j] >= '0' && n[j] <= '9') ; j ++){
                num *= 10;
                num += n[j] - '0';
            }
            if (num <= 2){
                continue;
            }
            n.erase(i , j - i);
            n.insert(i , f(num));
            i --;
        }
    }
    cout << n << endl;
    return 0;
}