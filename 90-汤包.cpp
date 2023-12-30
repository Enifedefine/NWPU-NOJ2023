#include <iostream>
using namespace std;
int l[100005];
int ll[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        int t,d;
        cin >> t >> d;
        l[i] = t + d;
        ll[i] = i;
    }
    for (int i = 1 ; i <= n ; i ++){
        for (int j = 1 ; j <= n - i ; j ++){
            if (l[j] > l[j + 1]){
                swap(l[j] , l[j + 1]);
                swap(ll[j] , ll[j+1]);
            }
        }
    }
    for (int i = 1 ; i <= n ; i ++){
        cout << ll[i] << " ";
    }
    return 0;
}