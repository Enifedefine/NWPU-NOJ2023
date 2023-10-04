#include <iostream>
using namespace std;
int main() {
    long long n , add , ans;
    cin >> n;
    ans = 0;
    for (long long i = 1 ; i <= n ; i ++){
        add = 0;
        for (long long j = i ; j <= n ; j ++){
            add += j;
            if (add == n){
                ans += 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}