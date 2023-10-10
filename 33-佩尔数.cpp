#include <iostream>
using namespace std;
int f1(int n){
    return (n < 2) ? n : 2 * f1(n - 1) + f1(n - 2);
}
int f2(int n){
    int a , b , c;
    a = 0;
    b = 1;
    c = 2;
    if (n < 3){
        return n;
    }
    for (int i = 3 ; i <= n ; i ++){
        a = b;
        b = c;
        c = a + 2 * b;
    }
    return c;
}
int main() {
    int n;
    cin >> n;
    cout << ((n % 2 == 1) ? f1(n) : f2(n)) << endl;
    return 0;
}
