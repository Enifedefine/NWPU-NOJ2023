#include <iostream>
using namespace std;
int main() {
    unsigned long long n;
    cin >> n;
    unsigned long long add = 0;
    for (unsigned long long i = 1 ; ; i ++){
        if (add + i > n){
            cout << n - add << endl;
            break;
        }
        add += i;
    }
    return 0;
}