#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = -n; row <= n; ++row) {
        int max_val = n - abs(row);

        for (int i = 0; i < abs(row); ++i) {
            cout << "  ";
        }
        for (int i = 0; i < max_val; ++i) {
            cout << i << " ";
        }
        for (int i = max_val; i > 0; --i) {
            cout << i << " ";
        }

        cout << 0 << endl;
    }

    return 0;
}

