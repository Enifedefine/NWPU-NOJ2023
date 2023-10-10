#include <iostream>
using namespace std;
bool is_prime(long long n){
    if (n % 2 == 0){
        return false;
    }
    for (long long i = 3 ; i * i <= n ; i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
int main() {
    long long a , b;
    cin >> a >> b;
    long long sum = 0;
    for (long long i = a ; i <= b ; ){
        sum += is_prime(i) ? 1 : 0;
        if (i % 6 == 0){
            i += 1;
        }
        else if (i % 6 < 5){
            i += 5 - (i % 6);
        }
        else{
            i += 2;
        }
    }
    cout << sum << endl;
    return 0;
}
