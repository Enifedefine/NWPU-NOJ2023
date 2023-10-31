#include <iostream>
using namespace std;
int l[7];
// 5 3 1 0
int main() {
    while (true){
        int ans = 0;
        for (int i = 1 ; i <= 6 ; i ++){
            cin >> l[i];
        }
        if (l[1] + l[2] + l[3] + l[4] + l[5] + l[6] == 0){
            break;
        }
        int blank1x1 = 0;
        int blank2x2 = 0;
        // 处理 6x6 5x5 4x4 3x3
        ans += l[6] + l[5] + l[4] + ((l[3] + 3) / 4);
        // 处理 2x2
        blank2x2 += l[4] * 5;
        if (l[3] % 4 == 1){
            blank2x2 += 5;
            blank1x1 += 7;
        }
        else if (l[3] % 4 == 2){
            blank2x2 += 3;
            blank1x1 += 6;
        }
        else if (l[3] % 4 == 3){
            blank2x2 += 1;
            blank1x1 += 5;
        }
        l[2] -= (blank2x2 <= l[2]) ? blank2x2 : l[2];
        if (l[2] > 0){
            ans += (l[2]+8)/9;
            blank1x1 += 36 - (l[2]%9)*4;
        }
        // 处理 1x1
        l[1] -= (blank1x1 <= l[1]) ? blank1x1 : l[1];
        if (l[1] > 0){
            ans += (l[1]+35)/36;
        }
        cout << ans << endl;
    }
    return 0;
}
