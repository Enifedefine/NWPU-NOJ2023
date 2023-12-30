#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int fib[100005] = {1 , 1 , 2};
int endd = 2;
int f(int cnt){
    if (cnt > endd){
        for (endd ++ ; endd <= cnt ; endd ++){
            fib[endd] = fib[endd - 1] + fib[endd - 2];
        }
        
    }
    return fib[cnt];
}
int main(){
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 1 ; s[i] != '\0' ; i ++){
        if (s[i] == 'm' || s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
        if (s[i] == 'n'){
            int cnt = 1;
            for (int j = i + 1 ; s[j] != '\0' ; j ++){
                if (s[j] == 'n'){
                    cnt ++;
                }
                else{
                    break;
                }
            }
            ans *= f(cnt);
            i += cnt;
        }
        if (s[i] == 'u'){
            int cnt = 1;
            for (int j = i + 1 ; s[j] != '\0' ; j ++){
                if (s[j] == 'u'){
                    cnt ++;
                }
                else{
                    break;
                }
            }
            ans *= f(cnt);
            i += cnt;
        }
    }
    cout << ans << endl;
    return 0;
}