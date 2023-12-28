#include <iostream>
#include <string>
using namespace std;
string str1 = "   AT\n  T--A\n A----T\nT------A\nT------A\n G----C\n  T--A\n   GC\n";
string str2 = "   CG\n  C--G\n A----T\nA------T\nT------A\n A----T\n  A--T\n   GC\n";
string str3 = "   AT\n  C--G\n T----A\nC------G\nC------G\n T----A\n  G--C\n   AT\n";
int main(){
    int n;
    cin >> n;
    for (int i = 1 ; i <= n/2 ; i ++){
        if (i % 3 == 1){
            cout << str1;
        }
        else if (i % 3 == 2){
            cout << str2;
        }
        else if (i % 3 == 0){
            cout << str3;
        }
    }
}

