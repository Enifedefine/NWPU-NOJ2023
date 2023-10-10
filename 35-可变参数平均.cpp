#include <iostream>
#include <stdarg.h>
using namespace std;
double avg(int n , ...){
    double sum = 0;
    va_list num;
    va_start(num, n);
    for (int i = 0 ; i < n ; i ++){
        sum += va_arg(num, double);
    }
    va_end(num);
    return sum / n;
}
int main() {
    double a , b , c , d , e;
    cin >> a >> b >> c >> d >> e;
    printf("%.4f\n" , avg(2 , a , b) - avg(3 , c , d , e));
    return 0;
}
