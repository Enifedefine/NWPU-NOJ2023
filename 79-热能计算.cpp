#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double Ti, Tf, m_liquid, c_liquid, m_container, c_container;
    cin >> Ti >> Tf >> m_liquid >> c_liquid >> m_container >> c_container;


    double Q_liquid = m_liquid * c_liquid * (Tf - Ti);
    double Q_container = m_container * c_container * (Tf - Ti);
    double Q = Q_liquid + Q_container;

    cout << fixed << setprecision(2);
    cout << Q / 1000 << "kJ," << Q_container/Q << "%," << Q_liquid/Q << "%" << endl;

    return 0;
}