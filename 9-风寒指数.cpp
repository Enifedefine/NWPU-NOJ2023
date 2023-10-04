#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double wind,temp;
    cin >> wind >> temp;
    double raw_chill = 13.12 + (0.6215*temp) - 11.37*pow(wind , 0.16) + 0.3965*temp*pow(wind , 0.16);
    cout << round(raw_chill);
    return 0;
}