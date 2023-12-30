#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double v , t;
    cin >> v >> t;
    double c = 331.3 * sqrt(1 + (t / 273.15));
    double m = v / 3.6 / c;
    printf("%.3f " , m);
    if (m < 0.8){
        cout << "subsonic" << endl;
    }
    else if (m < 1.2){
        cout << "transonic" << endl;
    }
    else if (m < 5.0){
        cout << "supersonic" << endl;
    }
    else if (m < 10.0){
        cout << "hypersonic" << endl;
    }
    return 0;
}