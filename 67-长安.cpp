// A点坐标在(1,1)
#include <iostream>
using namespace std;
int bx,by,px,py;
int map[1000][1000];
int find(){
    map[bx][by] = 1;
    for (int i = bx ; i >= 1 ; i --){
        for (int j = by ; j >= 1 ; j --){
            if (i == px && j == py){
                map[i][j] = 0;
                continue;
            }
            if (i == bx && j == by){
                continue;
            }
            if (i < bx && j < by){
                map[i][j] = map[i + 1][j] + map[i][j + 1];
            }
            if (i == bx){
                map[i][j] = map[i][j + 1];
            }
            if (j == by){
                map[i][j] = map[i + 1][j];
            }
        }
    }
    return map[1][1];
}
int main(){
    while (true){
        cin >> bx >> by >> px >> py;
        if (bx <= 0 || by <= 0 || px <= 0 || py <= 0){
            break;
        }
        cout << find() << endl;
    }
}