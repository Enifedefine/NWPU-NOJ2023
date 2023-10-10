#include <iostream>
#include <stdarg.h>
using namespace std;
int sum(int n1 , ...){
    int sum = 0;
    va_list num;
    va_start(num , n1);
    while(true){
        int n = va_arg(num, int);
        sum += n;
        if (n == 0){
            break;
        }
    }
    va_end(num);
    return sum + n1;
}
int main() {
    int a , b , c , d , e , f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << sum(a,b,0) - sum(c,d,e,f,0) << endl;
    return 0;
}
