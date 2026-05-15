#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int min = m;
    int max = m;
    int count = 0;

    while(n--) {
        cin >> m;
        if(m < min) {
            min = m;
            count++;
        } else if (m > max) {
            max = m;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
