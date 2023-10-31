#include <iostream>
using namespace std;
int map[305][305];
bool is_perfect(int n1 , int m1 , int n2 , int m2){
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = n1 ; i <= n2 ; i ++){
        for (int j = m1 ; j <= m2 ; j ++){
            if (i == n1 || i == n2 || j == m1 || j == m2){
                if (map[i][j] != 1){
                    return false;
                }
            }
            else{
                if (map[i][j] == 0){
                    cnt0 ++;
                }
                else{
                    cnt1 ++;
                }
            }
        }
    }
    if (abs(cnt0 - cnt1) > 1){
        return false;
    }
    return true;
}
int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++){
        for (int j = 1 ; j <= m ; j ++){
            cin >> map[i][j];
        }
    }
    int ans = 0;
    for (int n1 = 1 ; n1 <= n ; n1 ++){
        for (int m1 = 1 ; m1 <= m ; m1 ++){
            for (int n2 = n1 + 1 ; n2 <= n ; n2 ++){
                for (int m2 = m1 + 1 ; m2 <= m ; m2 ++){
                    if (is_perfect(n1, m1, n2, m2)){
                        //cout << n1 << m1 << n2 << m2 << endl;
                        ans ++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
