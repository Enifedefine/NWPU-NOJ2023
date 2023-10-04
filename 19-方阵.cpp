#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    for (long long i = 0 ; i < n ; i ++){
        for (long long j = i ; j > i - n ; j --){
            cout << abs(j);
            if (j != i - n + 1){
                cout << "  ";
            }
        }
        if (i != n - 1){
            cout << endl;
        }   
    }
    return 0;
}