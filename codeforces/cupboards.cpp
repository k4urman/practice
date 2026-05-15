#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, l, r, lsum(0), rsum(0);
    cin >> n;
    m = n;

    while(m--){
        cin >> l >> r;
        lsum += l;
        rsum += r;
    }

    cout << min(lsum, n - lsum) + min(rsum, n - rsum) << endl;

    return 0;

}
