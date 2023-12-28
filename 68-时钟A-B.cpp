#include <iostream>
#include <ctime>
using namespace std;
int main() {
    tm start_time = {};
    tm end_time = {};
    cin >> start_time.tm_year >> start_time.tm_mon >> start_time.tm_mday;
    cin >> end_time.tm_year >> end_time.tm_mon >> end_time.tm_mday;
    start_time.tm_mon -= 1;
    start_time.tm_year -= 1900;
    end_time.tm_mon -= 1;
    end_time.tm_year -= 1900;
    time_t start_seconds = mktime(&start_time);
    time_t end_seconds = mktime(&end_time);
    time_t difference = difftime(start_seconds , end_seconds);
    cout << difference << ".000000" << endl;
    return 0;
}