#include <iostream>
using namespace std;
struct student{
    long long id;
    char name[31];
    int score;
} l[10005];
int n;
void my_sort(){
    for (int i = 1 ; i <= n ; i ++){
        for (int j = 1 ; j <= n - i ; j ++){
            if (l[j].score < l[j+1].score){
                swap(l[j] , l[j+1]);
            }
            else if (l[j].score == l[j+1].score && l[j].id > l[j+1].id){
                swap(l[j] , l[j+1]);
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> l[i].id >> l[i].name >> l[i].score;
    }
    my_sort();
    for (int i = 1 ; i <= n ; i ++){
        cout << l[i].id << " " << l[i].name << " " << l[i].score << endl;
    }
    return 0;
}