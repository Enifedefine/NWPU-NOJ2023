#include <iostream>
using namespace std;
bool is_com[10000007];
int prime[10000007];
int main() {
    int n , ans = 0;
    cin >> n;
    for (int i = 2 ; i <= n ; i ++){
        if (!is_com[i]){
            ans ++;
            prime[ans] = i;
        }
        for (int j = 1 ; i * prime[j] <= n ; j ++){
            is_com[i * prime[j]] = true;
            if (i % prime[j] == 0){
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
