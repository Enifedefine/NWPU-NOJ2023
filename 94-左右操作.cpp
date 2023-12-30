#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(char a , char b){
    return a > b;
}
int main() {
    string str;
    cin >> str;
    int n = str.length();
    sort(str.begin() , str.begin() + n/2 , cmp);
    int j = (n%2)?(n/2+1):(n/2);
    for (int i = n - 1 ; i >= j ; i -- , j ++){
        swap(str[i] , str[j]);
    }
    cout << str << endl;
    return 0;
}