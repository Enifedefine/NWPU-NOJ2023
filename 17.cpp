#include <iostream>
using namespace std;
int a[100];
int main() {
    long long n;
    cin >> n;
    int i = 0;
    for ( ; n > 0 ; n /= 10){
        a[i] = n%10;
        i ++;
    }
    int flag = 1;
    for (int j = 0 ; j < i ; j ++){
        if (a[j] == 2 || a[j] == 3 || a[j] == 4 || a[j] == 5 || a[j] == 7){
            flag = 0;
            break;
        }
        if (a[j] == 0){
            if (a[i - j - 1] != 0){
                flag = 0;
                break;
            }
        }
        if (a[j] == 1){
            if (a[i - j - 1] != 1){
                flag = 0;
                break;
            }
        }
        if (a[j] == 6){
            if (a[i - j - 1] != 9){
                flag = 0;
                break;
            }
        }
        if (a[j] == 8){
            if (a[i - j - 1] != 8){
                flag = 0;
                break;
            }
        }
        if (a[j] == 9){
            if (a[i - j - 1] != 6){
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}