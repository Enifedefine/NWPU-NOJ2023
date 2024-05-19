#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int c[maxn];
long long dp[maxn];
int main () {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        int x;
        cin >> x;
        c[x]++;
    }
    for (int i = 1 ; i < maxn ; i ++) {
        dp[i] = max(dp[i - 2] + (i - 1) * c[i - 1] , dp[i - 1]);
    }
    cout << dp[maxn - 1] << endl;
    return 0;
}