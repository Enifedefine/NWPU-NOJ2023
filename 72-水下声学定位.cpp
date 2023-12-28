#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double heron(double a , double b , double c){
    double p = (a + b + c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main() {
    double ab,bc,cd,da,bd,ac,angle;
    cin >> ab >> bc >> cd >> da >> bd;
    printf("%.6f " , heron(ab , bc , bd) + heron(cd , da , bd));
    double abd = acos((ab*ab + bd*bd - da*da)/(2*ab*bd));
    double cbd = acos((bc*bc + bd*bd - cd*cd)/(2*bc*bd));
    double abc = abd + cbd;
    ac = sqrt(ab*ab + bc*bc - 2*ab*bc*cos(abc));
    angle = acos(((ab*ab + cd*cd) - (da*da + bc*bc))/(2*ac*bd));
    printf("%.1f\n" , 180 - angle*180.0/3.1415926);
    return 0;
}