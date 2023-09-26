#include <iostream>
#include <cmath>
using namespace std;
double rad(double num){
    return num * M_PI / 180.0;
}
int main(){
    double loc1_lon , loc1_lat;
    double loc2_lon , loc2_lat;

    cin >> loc1_lat >> loc1_lon;
    cin >> loc2_lat >> loc2_lon;

    double d_lat = rad(loc1_lat - loc2_lat);
    double d_lon = rad(loc1_lon - loc2_lon);
    //printf("%f\n" , d_lat);
    //printf("%f\n" , d_lon);
    //printf("%f\n" , (loc1_lat - loc2_lat) * M_PI / 180.0);
    double a = pow(sin(d_lat / 2.0), 2) + 
                (pow(sin(d_lon / 2.0), 2) * 
                cos(rad(loc1_lat)) * cos(rad(loc2_lat)));
    double radius = 6371.0;
    //printf("%f\n" , a);
    double c = 2 * asin(sqrt(a));
    printf("%0.4fkm" , radius*c);
    return 0;
}