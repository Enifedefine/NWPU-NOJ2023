#include <iostream>
using namespace std;
int numLen(int n){
    if (n == 0){
        return 1;
    }
    int ans = 0;
    for ( ; n > 0 ; n /= 10){
        ans ++;
    }
    return ans;
}
void putChar(char x , int n){
    for (int i = 1 ; i <= n ; i ++){
        cout << x;
    }
}
int main() {
    int a , b;
    cin >> a >> b;
    int len = numLen(a * b) + 1;
    putChar(' ' , len - numLen(a));
    cout << a << endl << 'x';
    putChar(' ' , len - numLen(b) - 1);
    cout << b << endl;
    putChar('-' , len);
    cout << endl;
    int bb = b;
    int cnt = 0;
    for ( ; bb > 0 ; bb /= 10 , cnt ++){
        if (bb / 10 == 0){
            cout << "+";
            len -= 1;
        }
        putChar(' ' , len - numLen((bb % 10) * a) - cnt);
        cout << (bb % 10) * a;
        putChar(' ' , cnt);
        cout << endl;
    }
    len += 1;
    putChar('-' , len);
    cout << endl;
    putChar(' ' , len - numLen(a * b));
    cout << a * b << endl;
    return 0;
}
