#include <iostream>
using namespace std;
double pow(double base , int exp = 2){
    double ans = 1;
    for ( ; exp > 1 ; ){
        if (exp % 2 == 0){
            base = base * base;
            exp /= 2;
        }
        else{
            ans = ans * base;
            base = base * base;
            exp /= 2;
        }
    }
    return ans * base;
}
int main() {
    double base;
    int exp;
    cin >> base >> exp;
    printf("%.6f\n" , pow(base));
    printf("%.6f\n" , pow(base , exp));
    return 0;
}