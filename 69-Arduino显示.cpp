#include <iostream>
using namespace std;
int l[10] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int find(int n){
    if (n == 0){
        return 6;
    }
    int ans = 0;
    for (; n > 0 ; n /= 10){
        ans += l[n % 10];
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0 ; i <= 99 ; i ++){
        for (int j = 0 ; j <= 99 ; j ++){
            if (find(i) + find(j) + find(i + j) + 4 == n){
                //cout << i << j << endl;
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}