#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct plane{
    string id;
    double x,y;
};
plane l[10005];
int main() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> l[i].id >> l[i].x >> l[i].y;
    }
    string min_id;
    double min_dis = 0x7fffffff;
    for (int i = 1 ; i <= n ; i ++){
        for (int j = i + 1 ; j <= n ; j ++){
            double dis = sqrt((l[i].x - l[j].x)*(l[i].x - l[j].x) + (l[i].y - l[j].y)*(l[i].y - l[j].y));
            if (dis < min_dis){
                min_dis = dis;
                min_id = l[i].id + "-";
                min_id += l[j].id;
            }
        }
    }
    printf("%s %.4f\n" , min_id.c_str() , min_dis);
    return 0;
}