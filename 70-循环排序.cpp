#include <iostream>
using namespace std;
int l[10000];
int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        cin >> l[i];
    }
    for (int start = 0 ; start < n - 1 ; start++) {
        int item = l[start];
        int pos = start;
        for (int i = start + 1 ; i < n ; i++) {
            if (l[i] < item) {
                pos ++;
            }
        }
        if (pos == start) {
            continue;
        }
        while (item == l[pos]) {
            pos ++;
        }
        swap(item, l[pos]);
        while (pos != start) {
            pos = start;
            for (int i = start + 1 ; i < n ; i++) {
                if (l[i] < item) {
                    pos ++;
                }
            }
            while (item == l[pos]) {
                pos ++;
            }
            swap(item, l[pos]);
        }
    }
    for (int i = 0 ; i < n ; i ++){
        cout << l[i] << " ";
    }
    return 0;
}