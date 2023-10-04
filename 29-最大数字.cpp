#include <iostream>
using namespace std;
bool judge(int n){
    for ( ; n > 0 ; n /= 10){
        if (n % 10 < (n / 10) % 10){
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = n ; i >= 0 ; i --){
        if (judge(i)){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
