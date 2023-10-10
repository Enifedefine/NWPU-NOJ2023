#include <iostream>
using namespace std;
int l[40] = { 14, 19, 28, 47,
    61, 75, 197, 742,
    1104, 1537, 2208, 2580,
    3684, 4788, 7385, 7647,
    7909, 31331, 34285, 34348,
    55604, 62662, 86935, 93993,
    120284, 129106, 147640, 156146,
    174680, 183186, 298320, 355419,
    694280, 925993, 1084051, 7913837,
    11436171, 33445755, 44121607 };
inline int isKeith(int n){
    for (int i = 0 ; i <= 38 ; i ++){
        if (n == l[i]){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    cout << (isKeith(n) ? "Yes" : "No");
    return 0;
}
