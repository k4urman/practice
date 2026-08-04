#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;

    vector<int> pref_01(n + 1, 0);
    vector<int> pref_10(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pref_01[i + 1] = pref_01[i] + (s[i] == '0' && t[i] == '1');
        pref_10[i + 1] = pref_10[i] + (s[i] == '1' && t[i] == '0');
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int len = r - l + 1;
        
        int n01 = pref_01[r] - pref_01[l - 1];
        int n10 = pref_10[r] - pref_10[l - 1];
        
        if (2 * max(n01, n10) <= len) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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

