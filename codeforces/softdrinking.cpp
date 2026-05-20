#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int mltoasts = (k * l)/ nl;
    int limes = c * d;
    int salt = p/np;

    cout << (min({mltoasts, limes, salt}))/n << endl;
    return 0;
}
