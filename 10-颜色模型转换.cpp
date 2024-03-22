#include <iostream>
#include <math.h>   
using namespace std;
double three_max(double a, double b, double c){
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}
double three_min(double a, double b, double c){
    return min(a,min(b,c));
}
int main(){
    double r, g, b, h, s, v;
    cin >> r >> g >> b;
    r /= 255.0;
    g /= 255.0;
    b /= 255.0;
    double my_max = three_max(r, g, b);
    double my_min = three_min(r, g, b);
    //carculate h
    if (my_max == my_min){
        h = 0;
    }
    else if (my_max == r && g >= b){
        h = 0 + 60 * (g - b) / (my_max - my_min);
    }
    else if (my_max == r && g < b){
        h = 360 + 60 * (g - b) / (my_max - my_min);
    }
    else if (my_max == g){
        h = 120 + 60 * (b - r) / (my_max - my_min);
    }
    else if (my_max == b){
        h = 240 + 60 * (r - g) / (my_max - my_min);
    }
    //carculate s
    if (my_max == 0){
        s = 0;
    }
    else{
        s = 1 - my_min/my_max;
    }
    //carculate v
    v = my_max;
    //print
    printf("%.4f,%.4f%%,%.4f%%\n", h, s*100, v*100);
    return 0;
}
