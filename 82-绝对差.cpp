#include <iostream>
#include <cmath>
using namespace std;
long long l[100005];
int main(){
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> l[i];
    }
    long long minn = abs(l[1] - l[2]);
    for (int i = 1 ; i <= n ; i ++){
        for (int j = i + 1 ; j <= n ; j ++){
            minn = min(minn , abs(l[i] - l[j]));
        }
    }
    cout << minn << endl;
    return 0;
}