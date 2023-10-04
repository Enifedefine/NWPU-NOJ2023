#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int a = 1 ; a < n / 3 ; a ++) {
        int b = (n * n - 2 * n * a) / (2 * n - 2 * a);
        int c = n - a - b;
        if (a * a + b * b == c * c) {
            cout << a * b * c << endl;
            return 0;
        }
    }
    return 0;
}
