#include <iostream>
#include <cmath>
using namespace std;
int cnt(int n){
    if (n <= 2){
        return 0;
    } 
    else if (n == 3){
        return 1;
    }
    else if (n == 4){
        return 3;
    }
    else{
        return 2 * cnt(n-1) + pow(2,n-4) - cnt(n-4);
    }
}
int main(){
    int n;
    while (cin >> n){
        if (n <= 0){
            break;
        }
        cout << cnt(n) << endl;
    }
    return 0;
}