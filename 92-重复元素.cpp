#include <iostream>
#include <map>
using namespace std;
map<int , int> l;
int main() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        int x;
        cin >> x;
        l[x] ++;
    }
    int ans = 0;
    for (auto it : l){
        ans += it.second - 1;
    }
    cout << ans << endl;
    return 0;
}