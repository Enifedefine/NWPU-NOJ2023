#include <iostream>
using namespace std;
int main() {
    long long k;
    cin >> k;
    long long n = 1;
    for (long long i = 2 ; i * i <= k ; i ++){
        if (k % i == 0){
            long long count = 0;
            while (k % i == 0){
                k /= i;
                count ++;
            }
            n = max(n, count * i);
        }
    }
    if (k > 1){
        n = max(n, k);
    }
    cout << n << endl;
    return 0;
}