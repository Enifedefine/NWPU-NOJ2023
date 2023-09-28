#include <iostream>
#include <vector>
using namespace std;
int main() {
    unsigned long long a,b,m,ans;
    cin >> a >> b >> m;
    ans = 1;
    for ( ; b > 1 ; ){
        if (b % 2 == 0){
            a = (a * a) % m;
            b /= 2;
        }
        else{
            ans = (ans * a) % m;
            a = (a * a) % m;
            b /= 2;
        }
    }
    cout << (ans * a) % m;
    return 0;
}