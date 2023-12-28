#include <iostream>
#include <vector>
using namespace std;
vector<int> l;
int n , key;
int f(int left , int right){
     if (right < left){
        return -1;
    }
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    if (key == l[mid1]){
        return mid1;
    }
    else if (key == l[mid2]){
        return mid2;
    }
    if (key < l[mid1]){
        return f(left , mid1 - 1);
    }
    else if (key > l[mid2]){
        return f(mid2 + 1 , right);
    }
    else if (key >= l[mid1] && key <= l[mid2]){
        return f(mid1 + 1 , mid2 - 1);
    }
    return -1;
}
int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        int num;
        cin >> num;
        l.push_back(num);
    }
    cin >> key;
    printf("%d in [%d]\n" , key , f(0 , n-1));
    return 0;
}

