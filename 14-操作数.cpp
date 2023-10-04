#include <iostream>
#include <math.h>
using namespace std;
long long cal(long long n){
    long long ans = 0;
    for (; n > 0; n/=10){
        ans += n%10;
    }
    return ans;
}
int main(){
    long long n;
    cin >> n;
    int ans = 0;
    for (; n > 0;n -= cal(n)){
        ans += 1;
    }
    cout << ans;
    return 0;
}