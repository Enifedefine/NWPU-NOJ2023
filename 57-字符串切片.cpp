#include <iostream>
#include <string>
using namespace std;
int main(){
    string src;
    int t;
    getline(cin , src);
    cin >> t;
    while (t --){
        int n , start , stop = src.length() , step = 1;
        cin >> n;
        if (n == 1){
            cin >> start;
        }
        else if (n == 2){
            cin >> start >> stop;
        }     
        else if (n == 3){
            cin >> start >> stop >> step;
        }
        //cout << start << "," << stop << "," << step << endl;
        if (start > stop && step > 0){
            stop = stop >= 0 ? stop : src.length() + stop;
        }
        else if (start < stop && step < 0){
            start = start >= 0 ? start : src.length() + start;
        }
        for (int i = start ; ; i += step){
            int pos = i >= 0 ? i : src.length() + i;
            if (step > 0 && i >= stop){
                break;
            }
            if (step < 0 && i <= stop){
                break;
            }
            cout << src[pos];
        }
        cout << endl;
    }
    return 0;
}