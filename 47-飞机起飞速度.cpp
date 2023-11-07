// Unfinished yet
#include <iostream>
using namespace std;
char CR[8][10] = {
    {'A','A','A','A','A','A','B','B','B','C'},
    {'A','A','A','A','A','A','B','B','B','C'},
    {'A','A','A','A','A','A','B','B','C','C'},
    {'A','A','A','A','A','B','B','C','C','D'},
    {'B','B','B','B','B','C','C','C','D','E'},
    {'C','C','C','C','C','D','D','E','E','E'},
    {'D','D','D','E','E','E',' ',' ',' ',' '},
    {'E','E',' ',' ',' ',' ',' ',' ',' ',' '}
};
int main() {
    double temp , pres;
    int elev , runw , wei , flap , wet;
    cin >> temp >> pres;
    cin >> elev >> runw >> wei >> flap >> wet;
    char r = CR[(int)floor((elev + 1000 * (29.92 - pres)) / 1000)][int(floor(temp)) / 10];
    
    return 0;
}
