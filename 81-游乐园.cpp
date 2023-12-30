#include <iostream>
using namespace std;
int n;
long long map[15][15];
int record[15];
long long length = 0;
long long max_length = 0;
void dfs(int now){
    max_length = max(max_length , length);
    for (int i = 1 ; i <= n ; i ++){
        if (map[now][i] != 0 && record[i] == 0){
            record[i] = 1;
            length += map[now][i];
            dfs(i);
            length -= map[now][i];
            record[i] = 0;
        }
    }
}
int main(){
    int m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++){
        int a,b,c;
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;
    }
    for (int i = 1 ; i <= n ; i ++){
        record[i] = 1;
        length = 0;
        dfs(i);
        record[i] = 0;
    }
    cout << max_length << endl;
    return 0;
}