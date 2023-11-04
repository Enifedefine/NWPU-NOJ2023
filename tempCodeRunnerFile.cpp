#include <iostream>
using namespace std;
int map[105][105];
int main() {
    int n,m;
    cin >> n >> m;
    double cnt = 0;
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            cin >> map[i][j];
            if (map[i][j] != 0){
                cnt ++;
            }
        }
    }
    if (cnt/(m*n) <= 0.05 && (cnt == m || cnt == n)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}
