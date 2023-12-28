#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double initialM, dryM, burnTime, cE, g;
    cin >> initialM >> dryM >> burnTime >> cE >> g;

    double propellantM = initialM - dryM;
    double m = propellantM / burnTime;
    double thrust = m * cE;

    double v = 0.0;
    double altitude = 0.0;
    const double timestep = 0.1;

    for (double currentTime = 0.0 ; currentTime <= burnTime ; currentTime += timestep) {
        double a = thrust / (propellantM + dryM);
        v += a * timestep;
        altitude += v * timestep;
        propellantM -= m * timestep;
    }
    cout << fixed << setprecision(3) << altitude / 1000 << "km"<< endl;

    return 0;
}