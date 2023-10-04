#include <iostream>
using namespace std;
int main(){
    int d = 0;
    cin >> d;
    switch (d){
    case 1:
        cout << sizeof(char) << "," << "-128" << "," << "127";
        break;
    case 2:
        cout << sizeof(unsigned char) << "," << "0" << "," << "255";
        break;
    case 3:
        cout << sizeof(short) << "," << "-32768" << "," << "32767";
        break;
    case 4:
        cout << sizeof(unsigned short) << "," << "0" << "," << "65535";
        break;
    case 5:
        cout << sizeof(int) << "," << "-2147483648" << "," << "2147483647";
        break;
    case 6:
        cout << sizeof(unsigned int) << "," << "0" << "," << "4294967295";
        break;
    case 7:
        cout << sizeof(long) << "," << "-2147483648" << "," << "2147483647";
        break;
    case 8:
        cout << sizeof(unsigned long) << "," << "0" << "," << "4294967295";
        break;
    case 9:
        cout << sizeof(long long) << "," << "-9223372036854775808" << "," << "9223372036854775807";
        break;
    case 10:
        cout << sizeof(unsigned long long) << "," << "0" << "," << "18446744073709551615";
        break;
    }
    return 0;
}