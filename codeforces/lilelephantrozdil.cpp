#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min(2e9), minidx(-1), count(0);

    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;

        if (m < min) {
            min = m;
            minidx = i;
            count = 1;
        } else if (m == min) {
            count++;
        }
    }

    if (count == 1) {
        cout << minidx << "\n";
    } else {
        cout << "Still Rozdil\n";
    }

    return 0;
}

