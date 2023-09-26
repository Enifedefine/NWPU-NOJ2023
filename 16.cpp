#include <iostream>
using namespace std;
long long gcd(long long n , long long m){
    if (n % m == 0){
        return m;
    }     
    return gcd(m, n % m);
}
int main() {
    long double num;
    cin >> num;
    num = static_cast<int>(num * 10000);
    long long i = 10000;
    long long g = gcd(num , i);
    cout << num/g << "/" << i/g << endl;
    return 0;
}