#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<string , int> l;
    for (int i = 0 ; s[i] != '\0' ; i ++){
        string name(1, s[i]);
        int cnt = 0;
        int j = i + 1;
        for ( ; s[j] != '\0' ; j ++){
            if (s[j] >= 'a' && s[j] <= 'z'){
                name.append(1 , s[j]);
            }
            if (s[j] >= '0' && s[j] <= '9'){
                cnt *= 10;
                cnt += s[j] - '0';
            }
            if (s[j] >= 'A' && s[j] <= 'Z'){
                break;
            }
        }
        if (cnt == 0){
            cnt = 1;
        }
        l[name] += cnt;
        i = j - 1;
    }
    for (auto& p : l){
        cout << p.first << " " << p.second << endl;
    } 
    return 0;
}