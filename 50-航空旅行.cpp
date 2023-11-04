#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e; // d:托运 e:携带
        if (a <= e && (b+c) <= d){
            cout << "YES" << endl;
        }
        else if (b <= e && (a+c) <= d){
            cout << "YES" << endl;
        }
        else if (c <= e && (a+b) <= d){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
