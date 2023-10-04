#include <iostream>
using namespace std;
int main() {
    int n , k , ans;
    ans = 0;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i ++){
        ans += k % i;
    }
    cout << ans << endl;
    return 0;
}