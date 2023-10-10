#include<iostream>
#include<cmath>
using namespace std;
int f(int n){
	int sum = n;
	for(int i = 2 ; i * i <= n ; i ++){
        if(n % i == 0){
			sum -= sum / i;
			while(n % i == 0){
                n /= i;
            }
		}
    }	
	if(n > 1) {
        sum -= sum / n;
    }
	return sum * 2;
}
int main(){
    int n;
	cin >> n;
	if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    long long ans = 3;
	for(int i = 2 ; i <= n - 1 ; i ++){
        ans += f(i);
    }
    cout << ans << endl;
	return 0;
}