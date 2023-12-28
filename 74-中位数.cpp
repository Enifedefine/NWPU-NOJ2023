#include <iostream>
#include <stack>
using namespace std;
int l[100005];
int ll[100005];
int start = 1;
int endd = 0;
void p(){
    printf("start = %d , endd = %d\n" , start , endd);
    for (int i = 1 ; i <= 10 ; i ++){
        cout << l[i] << ",";
    }
    cout << endl;
    for (int i = 1 ; i <= 10 ; i ++){
        cout << ll[i] << ",";
    }
}
int main() {
    int n;
    while(true){
        //p();
        cin >> n;
        if (n < 0){
            break;
        }
        if (n == 0){
            for (int i = 1 ; i <= endd ; i ++){
                printf("%d " , l[i]);
            }
            int step = 1 , mid1 , mid2;
            for (int i = start ; ; i = ll[i]){
                if (endd % 2 == 0){
                    if (step == endd/2){
                        mid1 = l[i];
                    }
                    if (step == endd/2 + 1){
                        mid2 = l[i];
                        break;
                    }
                }
                else{
                    if (step == endd/2 + 1){
                        mid1 = l[i];
                        mid2 = l[i];
                        break;
                    }
                }
                step ++;
            }
            printf("%f\n" , (mid1 + mid2) / 2.0);
            continue;
        }
        endd++;
        l[endd] = n;
        if (endd == 1){
            continue;
        }
        if (n < l[start]){
            ll[endd] = start;
            start = endd;
            continue;
        }
        for (int i = start ; ; ){
            if (ll[i] == 0){
                ll[i] = endd;
                break;
            }
            if (n < l[ll[i]]){
                ll[endd] = ll[i];
                ll[i] = endd;
                break;
            }
            i = ll[i];
        }
    }
    return 0;
}