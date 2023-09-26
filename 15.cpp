#include <iostream>
#include <math.h>
using namespace std;
long long string_to_num(string numstr , long long type){
    long long ans = 0;
    long long i = 0;
    for ( ; ; i ++){
        if (numstr[i] >= '0' && numstr[i] <= '9'){
            ans *= 10;
            ans += numstr[i] - '0';
        }
        else{
            i ++;
            break;
        }
    }
    if (type == 2){
        ans = 0;
        for ( ; ; i ++){
            if (numstr[i] >= '0' && numstr[i] <= '9'){
                ans *= 10;
                ans += numstr[i] - '0';
            }
            else{
                break;
            }
        }
    }

    return ans;
}
long long gcd(long long n , long long m){
    if (n % m == 0){
        return m;
    }     
    return gcd(m, n % m);
}
void my_plus(long long a , long long b , long long c , long long d){
    long long up,down,g;
    up = a * d + c * b;
    down = b * d;
    g = gcd(up , down);
    up /= g;
    down /= g;
    printf("(%lld/%lld)+(%lld/%lld)=%lld/%lld\n" , a , b , c , d , up , down);
}
void my_minus(long long a , long long b , long long c , long long d){
    long long up,down,g;
    up = a * d - c * b;
    down = b * d;
    g = gcd(up , down);
    up /= g;
    down /= g;
    printf("(%lld/%lld)-(%lld/%lld)=%lld/%lld\n" , a , b , c , d , up , down);
}
void my_times(long long a , long long b , long long c , long long d){
    long long up,down,g;
    up = a * c;
    down = b * d;
    g = gcd(up , down);
    up /= g;
    down /= g;
    printf("(%lld/%lld)*(%lld/%lld)=%lld/%lld\n" , a , b , c , d , up , down);
}
void my_over(long long a , long long b , long long c , long long d){
    long long up,down,g;
    up = a * d;
    down = b * c;
    g = gcd(up , down);
    up /= g;
    down /= g;
    printf("(%lld/%lld)/(%lld/%lld)=%lld/%lld\n" , a , b , c , d , up , down);
}
int main(){
    long long a,b,c,d; // a/b ; c/d
    string num1,num2;
    cin >> num1 >> num2;
    a = string_to_num(num1 , 1);
    b = string_to_num(num1 , 2);
    c = string_to_num(num2 , 1);
    d = string_to_num(num2 , 2);
    my_plus(a,b,c,d);
    my_minus(a,b,c,d);
    my_times(a,b,c,d);
    my_over(a,b,c,d);
    return 0;
}