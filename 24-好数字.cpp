#include <iostream>
using namespace std;
long long mod = 1000000007;
unsigned long long myPow(unsigned long long a , unsigned long long b) {
    unsigned long long ans = 1;
    if (b == 0){
        return 1;
    }
    for ( ; b > 1 ; ){
        if (b % 2 == 0){
            a = (a % mod * a % mod) % mod;
            b /= 2;
        }
        else{
            ans = (ans % mod * a % mod) % mod;
            a = (a % mod * a % mod) % mod;
            b /= 2;
        }
    }
    return (ans * a) % mod;
}
int main() {
    unsigned long long n , ans;
    cin >> n;
    if (n % 2 == 0){
        ans = myPow(5 , n / 2) * myPow(4 , n / 2);
    }
    else{
        ans = myPow(5 , (n / 2) + 1) * myPow(4 , n / 2);
    }
    cout << ans % mod << endl;
    return 0;
}