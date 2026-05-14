

#include <iostream>
using namespace std;

int main() {
    int count(0), total(0), n, x;

    cin >> n;

    while (n--) {
        cin >> x;
        total += x;
        count++;
    }

    double ans = (double)total/count;
    cout << ans << endl;

    return 0;
}

