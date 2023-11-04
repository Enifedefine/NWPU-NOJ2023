#include <iostream>
using namespace std;
int l[10000005][2]; //0:X 1:Y
int main() {
    int n;
    cin >> n;
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 1 ; i <= n ; i ++){
        cin >> l[i][0] >> l[i][1];
        sum_x += l[i][0];
        sum_y += l[i][1];
    }
    double avg_x = sum_x/n;
    double avg_y = sum_y/n;
    double b_up = 0;
    double b_down = 0;
    for (int i = 1 ; i <= n ; i ++){
        b_up += (l[i][0] - avg_x)*(l[i][1] - avg_y);
        b_down += (l[i][0] - avg_x)*(l[i][0] - avg_x);
    }
    double b = b_up/b_down;
    double a = avg_y - b*avg_x;
    printf("Y=%.4f+%.4f*X" , a , b);
    return 0;
}
