#include <iostream>
using namespace std;
int main() {
    long long n , x;
    cin >> n >> x;
    if (n % 2 == 1){
        cout << (n - 1) * 3 << endl;
    }
    else{
        cout << 3 * ((n / 2) + abs(x - (n / 2))) << endl;
    }
    return 0;
}
