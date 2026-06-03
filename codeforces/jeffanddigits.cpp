#include <iostream>

using namespace std;

int main() {
    int n, m, five(0), zero(0);
    cin >> n;

    while(n--) {
        cin >> m;
        if(m == 5) {
            five++;
        } else if (m == 0) {
            zero++;
        }
    }

    if (zero == 0) {
        cout << -1 << endl;
    } else if (five < 9) {
        cout << 0 << endl;
    } else if (five == 0) {
        cout << 0 << endl;
    } else {
        int count = five - (five % 9);
        for (int i = 0; i < count; i++) {
            cout << 5;
        }
        for (int i = 0; i < zero; i++) {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}
