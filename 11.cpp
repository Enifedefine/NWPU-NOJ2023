#include <iostream>
using namespace std;
int cal(int n) {
    int ans = 0;
    for (int i = 1; i < n; i ++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ans += i;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;
        cout << cal(n) << endl;
    }

    return 0;
}