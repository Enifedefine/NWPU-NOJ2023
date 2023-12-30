#include <iostream>
#include <algorithm>
using namespace std;
int a[55];
int main(){
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    int max = 0;
    int maxA , maxB , maxC;
    for (int i = 1 ; i <= n ; i ++){
        for (int j = i + 1 ; j <= n ; j ++){
            for (int k = j + 1 ; k <= n ; k ++){
                if (a[i] + a[j] > a[k]){
                    if (a[i] + a[j] + a[k] > max){
                        max = a[i] + a[j] + a[k];
                        maxA = a[i];
                        maxB = a[j];
                        maxC = a[k];
                    }
                    if (a[i] + a[j] + a[k] == max && a[k] > maxC){
                        maxA = a[i];
                        maxB = a[j];
                        maxC = a[k];
                    }
                    if (a[i] + a[j] + a[k] == max && a[k] == maxC && a[i] > maxA){
                        maxA = a[i];
                        maxB = a[j];
                        maxC = a[k];
                    }
                }
            }
        }
    }
    if (max == 0){
        cout << -1 << endl;
    }
    else{
        cout << maxA << " " << maxB << " " << maxC << endl;
    }
    return 0;
}