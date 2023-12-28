#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <string>
using namespace std;

double sunriseTime = 0.0;
double sunsetTime = 0.0;

double deg2rad(double degrees) {
    return degrees * M_PI / 180.0;
}

double rad2deg(double radians) {
    return radians * 180.0 / M_PI;
}

double calculateJulianDay(int year, int month, int day) {
    if (month <= 2) {
        year -= 1;
        month += 12;
    }
    int A = static_cast<int>(year / 100);
    int B = 2 - A + static_cast<int>(A / 4);
    double julianDay = static_cast<int>(365.25 * (year + 4716)) + static_cast<int>(30.6001 * (month + 1)) + day + B - 1524.5;
    return julianDay;
}

void calculateSunriseSunset(double latitude, double longitude, int year, int month, int day) {
    double julianDay = calculateJulianDay(year, month, day);
    double n = julianDay - 2451545.0 + 0.0008;
    double Jc = n / 36525.0;
    double Jd = 2451545.0 + 0.0009 + Jc;

    double M = fmod((357.5291 + 0.98560028 * (Jd - 2451545.0)), 360.0);
    double L = fmod((280.46646 + 0.98564736 * (Jd - 2451545.0)), 360.0);
    double ec = 0.016708634 - 0.000042037 * Jc;
    double C = (1.914602 - 0.004817 * Jc - 0.000014 * pow(Jc, 2)) * sin(deg2rad(M))
        + (0.019993 - 0.000101 * Jc) * sin(deg2rad(2 * M))
        + 0.000289 * sin(deg2rad(3 * M));
    double trueLongitude = L + C;
    double omega = 125.04 - 1934.136 * Jc;
    double lambdaSun = trueLongitude - 0.00569 - 0.00478 * sin(deg2rad(omega));
    double epsilon = 23.439291 - 0.0130042 * Jc;
    double sinAlpha = cos(deg2rad(epsilon)) * sin(deg2rad(lambdaSun));
    double cosAlpha = sqrt(1 - pow(sinAlpha, 2));
    double alpha = rad2deg(atan2(sinAlpha, cosAlpha));

    double hourAngle = rad2deg(acos((sin(deg2rad(-0.83)) - sin(deg2rad(latitude)) * sin(deg2rad(alpha)))
                                   / (cos(deg2rad(latitude)) * cos(deg2rad(alpha)))));

    double Jtransit = 2451545.0 + 0.0009 + ((hourAngle + longitude) / 360.0) + n;
    double deltaJtransit = Jtransit - floor(Jtransit);
    double Jset = Jtransit + (0.0053 * sin(deg2rad(omega))) - (0.0069 * sin(2 * deg2rad(lambdaSun)));
    double deltaJset = Jset - floor(Jset);
    double Jrise = Jtransit - deltaJtransit;
    double JriseNext = Jrise + 1.0;

    sunriseTime = (Jrise - 2451545.0) * 86400.0;
    sunsetTime = (Jset - 2451545.0) * 86400.0;
}

// 将秒转换为时分秒格式
string formatTime(double seconds) {
    int hours = static_cast<int>(seconds / 3600) % 24;
    int minutes = static_cast<int>((seconds / 60)) % 60;
    int remainingSeconds = static_cast<int>(seconds) % 60;
    char buffer[9];  // HH:MM:SS\0
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hours, minutes, remainingSeconds);
    return string(buffer);
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;
    double latitude, longitude;
    cin >> longitude >> latitude;  // Fix: Swap longitude and latitude

    // Assuming zone is not used in the calculation
    double zone;
    cin >> zone;

    // 调用 C++ 版本的计算函数
    calculateSunriseSunset(latitude, longitude, year, month, day);

    // Assuming sunriseTime and sunsetTime are in seconds
    int sunrise = static_cast<int>(sunriseTime);
    int sunset = static_cast<int>(sunsetTime);

    cout << "   Sunrise=" << formatTime(sunrise) << endl;
    cout << "    Sunset=" << formatTime(sunset) << endl;

    return 0;
}