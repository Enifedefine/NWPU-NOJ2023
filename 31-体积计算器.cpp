#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double pi = 3.1415926;
void VolCalc(double r){
    printf("%.6f\n" , (4.0/3.0) * pi * r * r * r);
} //球体
void VolCalc(double r,double h){
    printf("%.6f\n" , (1.0/3.0) * (pi * r * r) * h);
} //圆锥体
void VolCalc(long a){
    double b = a;
    printf("%.6f\n" , b * b * b);
}//立方体
void VolCalc(double r,long h){
    printf("%.6f\n" , (pi * r * r) * h);
} //圆柱体
void VolCalc(long l,long w,long h){
    double b = l * w * h;
    printf("%.6f\n" , b);
}//长方体
void VolCalc(double r,double R,double h,double l){
    h = R + sqrt(R*R - r*r);
    double v = (1.0/3.0) * pi * h * h * (3*R - h);
    printf("%.6f " , pi*r*r*l + v*2);
    h = R - sqrt(R*R - r*r);
    v = (1.0/3.0) * pi * h * h * (3*R - h);
    printf("%.6f\n" , pi*r*r*l + v*2);
} //胶囊
void VolCalc(double r,double R,double h){
    h = R + sqrt(R*R - r*r);
    printf("%.6f " , (1.0/3.0) * pi * h * h * (3*R - h));
    h = R - sqrt(R*R - r*r);
    printf("%.6f\n" , (1.0/3.0) * pi * h * h * (3*R - h));
} //球盖
void VolCalc(long r,double R,double h){
    printf("%.6f\n" , (1.0/3.0)*h*(pi*r*r + pi*R*R + sqrt(pi*r*r*pi*R*R)));
} //圆锥体
void VolCalc(double a,double b,long c){
    printf("%.6f\n" , (4.0/3.0)*pi*a*b*c);
} //椭球体
void VolCalc(long a,long h){
    long long b = a*a*h/3;
    double c = b;
    printf("%.6f\n" , c);
} //四棱锥
void VolCalc(long d1,long d2,double l){
    double dd1 = d1;
    double dd2 = d2;
    double s1 = (dd1/2)*(dd1/2)*pi;
    double s2 = (dd2/2)*(dd2/2)*pi;
    printf("%.6f\n" , (s1-s2)*l);
} //管件

int main() {
    long long t;
    cin >> t;
    while (t --){
        int n;
        cin >> n;
        if (n == 1){
            double r;
            cin >> r;
            VolCalc(r);
        }
        else if (n == 2){
            double r , h;
            cin >> r >> h;
            VolCalc(r , h);
        }
        else if (n == 3){
            long a;
            cin >> a;
            VolCalc(a);
        }
        else if (n == 4){
            double r;
            long h;
            cin >> r >> h;
            VolCalc(r , h);
        }
        else if (n == 5){
            long l , w , h;
            cin >> l >> w >> h;
            VolCalc(l , w , h);
        }
        else if (n == 6){
            double r , R , h , l;
            cin >> r >> R >> l;
            h = 0;
            VolCalc(r , R , h , l);
        }
        else if (n == 7){
            double r , R , h;
            cin >> r >> R;
            h = 0;
            VolCalc(r , R , h);  
        }
        else if (n == 8){
            long r;
            double R , h;
            cin >> r >> R >> h;
            VolCalc(r , R , h);
        }
        else if (n == 9){
            double a , b;
            long c;
            cin >> a >> b >> c;
            VolCalc(a , b , c);
        }
        else if (n == 10){
            long a , h;
            cin >> a >> h;
            VolCalc(a , h);
        }
        else if (n == 11){
            long d1 , d2;
            double l;
            cin >> d1 >> d2 >> l;
            VolCalc(d1 , d2 , l);
        }
    }
    return 0;
}