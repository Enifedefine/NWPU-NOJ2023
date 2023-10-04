#include <iostream>
using namespace std;
int main() {
    int a , b;
    cin >> a >> b;
    int ans = 0;
    while (a > 0){
        cout << a << " " << b << endl;
        if (a % 2 != 0){
            ans += b;
        }
        if (a == 1){
            break;
        }
        a /= 2;
        b *= 2;
    }
    cout << ans << endl;
    return 0;
}
