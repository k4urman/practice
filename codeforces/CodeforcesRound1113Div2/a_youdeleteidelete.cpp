#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    size_t first_zero = s.find('0');
    s.erase(first_zero, 1);

    size_t first_one = s.find('1');
    s.erase(first_one, 1);

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

