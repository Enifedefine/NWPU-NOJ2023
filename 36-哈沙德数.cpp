#include <iostream>
using namespace std;
int hn(int n){
    int num = n;
    int sum = 0;
    while (num){
        sum += num % 10;
        num /= 10;
    }
    if (sum && n % sum == 0){
        return n / sum;
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    if (n == hn(n)){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    while (true){
        if (hn(n) == 0 || hn(n) == n){
            break;
        }
        n = hn(n);
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
