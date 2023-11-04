//代数余子式法

#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> > det;
int pow(int x){
    if (x % 2 == 0){
        return 1;
    }
    else{
        return -1;
    }

}
int cal2x2(vector< vector<int> > x){
    return x[0][0]*x[1][1] - x[0][1]*x[1][0];
}
int cal(vector< vector<int> > x){
    if (x.size() == 2){
        return cal2x2(x);
    }
    int ans = 0;
    for (int i = 0 ; i < x.size() ; i ++){
        vector< vector<int> > xx = x;
        for (int j = 0 ; j < x.size() ; j ++){
            //cout << j << "," << i << endl;
            xx[j].erase(xx[j].begin() + i);
            //print (xx);
        }
        xx.erase(xx.begin());
        //print (xx);
        ans += pow(i+2)*x[0][i]*cal(xx);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        vector<int> temp;
        for (int j = 1 ; j <= n ; j ++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        det.push_back(temp);
    }
    cout << cal(det) << endl;
    return 0;
}
