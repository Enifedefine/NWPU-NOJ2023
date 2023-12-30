#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int name[4] = {1 , 2 , 5 , 10};
    int r[4] = {(n%10)%5%2 , (n%10)%5/2 , (n%10)/5 , n/10};
    for (int i = 0 ; i < 4 ; i ++){
        if (r[i] != 0){
            printf("%d=%d\n" , name[i] , r[i]);
        }
    }
    return 0;
}