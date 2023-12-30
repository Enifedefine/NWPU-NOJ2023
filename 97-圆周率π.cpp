#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double ans = 3.0;
	for (int i = 2; i <= n; i ++) {
	    if (i % 2 == 0){
            ans += 4.0 / ((2 * i - 2) * (2 * i - 1) * (2 * i));
        } 
        else{
            ans -= 4.0 / ((2 * i - 2) * (2 * i - 1) * (2 * i));
        }
	}
    printf("%.7f\n" , ans);
    return 0;
}