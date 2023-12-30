#include <iostream>
using namespace std;
long long l[100005];
int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i ++){
        long long x;
        cin >> x;
        l[x] = -1;
    }
    l[n] = 1;
    for (int i = n - 1 ; i >= 0 ; i --){
        if (l[i] == -1){
            l[i] = 0;
            continue;
        }
        l[i] = (l[i+1] + l[i+2]) % 1000000007;
    }
    cout << l[0] << endl;
    return 0;
}