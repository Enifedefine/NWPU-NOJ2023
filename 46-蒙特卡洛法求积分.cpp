#include <cmath>
#include <iostream>
#include <cmath>
#include <random>
using namespace std;
#define _USE_MATH_DEFINES
double func(int n , double x){
    if (n == 1) {
        return pow(x , 4)*pow(M_E , 0-x);
    }
    else if (n == 2){
        return (x*x + 1);
    }
    else if (n == 3){
        return cos(x);
    }
    else if (n == 4){
        return sqrt(x)*(x-2);
    }
    else if (n == 5){
        return 2*sin(x) - 5*cos(x);
    }
    return 0;
}
int main() {
    srand(RAND_MAX);
    int m , N;
    double a , b;
    cin >> m >> a >> b >> N;
    double value = 0;
    for (int i = 1 ; i <= N ; i ++){
        //cout << a + (b-a)*((double)rand()/RAND_MAX) << " ";
        //double x = a + (b-a)*((double)rand()/RAND_MAX);
        //value += func(m , x) * (b - a);   
        cout << rand() << endl; 
    }
    printf("%.6f\n" , value/N);
    //cout << (65.0/M_E)-(1569.0/pow(M_E,5));
    return 0;
}
