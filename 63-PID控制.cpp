#include <iostream>
using namespace std;

typedef struct PIDController{
    double Kp = 0, Ki = 0, Kd = 0; // 比例、积分、微分系数
    double preError = 0, integral = 0; // 前次误差、积分
} PIDData;

double PIDCalculate(PIDData *pid, double setpoint, double measuredValue){
    // ?
}

int main(){
    PIDData test;
    cin >> test.Kp >> test.Ki >> test.Kd;
    double setpoint, measuredValue;
    cin >> setpoint >> measuredValue;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cout << i << " ";
        cout << PIDCalculate(&test, setpoint, measuredValue) << endl;
    }
    return 0;
}