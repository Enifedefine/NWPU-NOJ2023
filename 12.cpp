#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1 ; i <= n ; i ++){
        int a = 0;
        if (i <= 8){
            a += i * 100;
            a += (i + 1) * 10;
        }
        else if (i == 9){
            a = 910;
        }
        else if (i <= 98){
            a += i * 100;
            a += i + 1;
        }
        else{
            a = 9910;
        }
        ans += a;
        if (a % 10 == 0){
            cout << a/100 << "." << a % 100 / 10;
        }
        else{
            cout << a/100 << "." << a % 100;
        }

        if (i != n){
            cout << "+";
        }
        else{
            cout << "=";
        }
        
    }
    if (ans % 10 == 0){
        cout << ans/100 << "." << ans % 100 / 10;
    }
    else{
        cout << ans/100 << "." << ans % 100;
    }
    
    return 0;
}