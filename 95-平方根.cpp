#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
int main() {
    FILE *fp1 = fopen("rr.dat", "w");
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        fprintf(fp1, "%.6f\n", sqrt(i));
    }
    fclose(fp1);
    FILE *fp2 = fopen("rr.dat", "r");
    for (int i = 1 ; i <= n ; i ++){
        char s[1005];
        fscanf(fp2, "%s", s);
        printf("%s ", s);
    }
    fclose(fp2);
    return 0;
}