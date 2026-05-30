#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int odd = (n+1)/2;

    if (k <= odd) {
        cout << (k*2) - 1 << endl;
    } else {
        cout << (k - odd) * 2 << endl;
    }

    return 0;
}
