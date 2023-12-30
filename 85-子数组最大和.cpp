#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];
int dp[10005];
int main(){
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i ++){
        dp[i] = max(a[i] , dp[i - 1] + a[i]);
    }
    int maxx = 0;
    for (int i = 1 ; i <= n ; i ++){
        maxx = max(maxx , dp[i]);
    }
    cout << maxx << endl;
    return 0;
}