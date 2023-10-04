#include <iostream>
using namespace std;
int m,n,d;
int map[100000][3];
void bfs(){
    map[0][0] = 0;
    map[0][1] = 0;
    map[0][2] = 0;
    int head = 0;
    for (int i = 0 ; ; i ++){
        //cout << map[i][0] << "," << map[i][1] << "," << map[i][2] << endl;
        int flag = 0;
        for (int j = 0 ; j < i ; j ++){
            if (map[j][0] == map[i][0] && map[j][1] == map[i][1]){
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            continue;
        }
        if (map[i][0] == d || map[i][1] == d){
            cout << map[i][2] << endl;
            break;
        }
        // empty m
        if (map[i][0] != 0){
            head += 1;
            map[head][0] = 0;
            map[head][1] = map[i][1];
            map[head][2] = map[i][2] + 1;
        }
        // empty n
        if (map[i][1] != 0){
            head += 1;
            map[head][0] = map[i][0];
            map[head][1] = 0;
            map[head][2] = map[i][2] + 1;
        }
        // full m
        if (map[i][0] != m){
            head += 1;
            map[head][0] = m;
            map[head][1] = map[i][1];
            map[head][2] = map[i][2] + 1;
        }
        // full n
        if (map[i][1] != n){
            head += 1;
            map[head][0] = map[i][0];
            map[head][1] = n;
            map[head][2] = map[i][2] + 1;
        }
        // m2n
        if (map[i][0] != 0){
            if (map[i][0] <= n - map[i][1]){
                head += 1;
                map[head][0] = 0;
                map[head][1] = map[i][0] + map[i][1];
                map[head][2] = map[i][2] + 1;
            }
            else{
                head += 1;
                map[head][0] = map[i][0] - (n - map[i][1]);
                map[head][1] = n;
                map[head][2] = map[i][2] + 1;
            }
        }
        
        // n2m
        if (map[i][1] != 0){
            if (map[i][1] <= m - map[i][0]){
                head += 1;
                map[head][0] = map[i][0] + map[i][1];
                map[head][1] = 0;
                map[head][2] = map[i][2] + 1;
            }
            else{
                head += 1;
                map[head][0] = m;
                map[head][1] = map[i][1] - (m - map[i][0]);
                map[head][2] = map[i][2] + 1;
            }
        }
    }
}
int main() {
    cin >> m >> n >> d;
    bfs();
    return 0;
}