#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pages(7);
    for (int i = 0; i < 7; ++i) {
        cin >> pages[i];
    }

    int day = 0;
    while (n > 0) {
        n -= pages[day];
        if (n <= 0) {
            cout << day + 1 << "\n";
            return 0;
        }
        day = (day + 1) % 7;
    }

    return 0;
}

