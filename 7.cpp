#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> m >> n;
    int num = 0;
    for (int i = m ; i != 0 ; i/= 10){
        num++;
    }
    if (n > num){
        for (int i = 1 ; i <= n-num ; i ++){
            printf("%d" , 0);
        }
    }
    cout << m;
    return 0;
}