#include <iostream>
#include <string>
using namespace std;
int s[100005];
int n;
long long sub_int(int a , int b){
    long long num = 0;
    for (int i = a ; i <= b ; i ++){
        num *= 10;
        num += s[i];
    }
    return num;
}
void print(int a , int b){
    for (int i = a ; i <= b ; i ++){
        cout << s[i];
    }
}
bool check(int a , int b , int c , int d){
    // print(a ,b);
    // cout << "+";
    // print(c , d);
    // cout << endl;
    for (int i = d + 1 ; i <= n ; i ++){
        if (sub_int(a , b) + sub_int(c , d) == sub_int(d + 1 , i)){
            if (i == n){
                return true;
            }
            if (check(c , d , d + 1 , i)){
                // cout << c << "," << d << " ";
                return true;
            }
        }
        if (sub_int(a , b) + sub_int(c , d) < sub_int(d + 1 , i)){
            break;
        }
    }
    return false;
}
int main() {
    string str_s;
    cin >> str_s;
    n = str_s.length();
    for (int i = 1 ; i <= n ; i ++){
        s[i] = str_s[i - 1] - '0';
    }
    for (int i = 1 ; i <= n ; i ++){
        for (int j = i + 1 ; j <= n ; j ++){
            if (check(1 , i , i+1 , j)){
                cout << "true" << endl;
                return 0;
            }
        }
    }
    cout << "false" << endl;
    return 0;
}