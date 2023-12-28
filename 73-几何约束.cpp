#include <iostream>
using namespace std;
struct line{
    int x1,y1,x2,y2;
    // y = ax + b
    double a,b;
};
line lines[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
        if (lines[i].x1 > lines[i].x2){
            swap(lines[i].x1 , lines[i].x2);
            swap(lines[i].y1 , lines[i].y2);
        }
        lines[i].a = ((double)lines[i].y2 - (double)lines[i].y1)/((double)lines[i].x2 - (double)lines[i].x1);
        lines[i].b = lines[i].y1 - lines[i].a * lines[i].x1;
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i ++){
        for (int j = i + 1 ; j <= n ; j ++){
            double x = (lines[j].b - lines[i].b)/(lines[i].a - lines[j].a);
            if (x >= lines[i].x1 && x <= lines[i].x2 && x >= lines[j].x1 && x <= lines[j].x2){
                printf("X: #%d #%d\n" , i , j);
                ans ++;
            }
        }
    }
    printf("n=%d\n" , ans);
    return 0;
}