#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 2){
        cout << ((n % 2 == 0) ? (n /= 2) : (n = 3 * n + 1)) << " ";
    }
    cout << 1;
    return 0;
}
