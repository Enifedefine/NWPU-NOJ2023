#include <iostream>
#include <string>
using namespace std;
int l[100];
int main(){
    l[0] = 1;
    l[1] = 1;
    int n;
    cin >> n;
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2 ; i <= n ; i ++){
        int ans = 0;
        for (int j = 2 ; j <= n*2 ; j += 2){
            ans += l[(j / 2) - 1] * l[((i*2) - j)/2];
        }
        l[i] = ans;
    }
    cout << l[n] << endl;
    return 0;
}