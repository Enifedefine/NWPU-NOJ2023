#include <iostream>
using namespace std;
int cal_char(char a , char b){
    if (a <= b){
        return b - a;
    }
    else{
        return b - a + 26;
    }
}
int cal_int(char a , char b){
    if (a <= b){
        return b - a;
    }
    else{
        return b - a + 10;
    }
}
int main() {
    char a[7] , b[7];
    cin >> a >> b;
    int ans = 0;
    for (int i = 0 ; i < 2 ; i ++){
        ans += cal_char(a[i] , b[i]);
    }
    for (int i = 2 ; i < 6 ; i ++){
        ans += cal_int(a[i] , b[i]);
    }
    cout << ans << endl;
    return 0;
}