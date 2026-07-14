#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    int maxt = 0;
    int curlen = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            curlen++;
        } else {
            if (curlen > 0) {
                int curtime = (curlen + 1) / 2;
                maxt = max(maxt, curtime);
                curlen = 0;
            }
        }
    }
    
    if (curlen > 0) {
        int curtime = (curlen + 1) / 2;
        maxt = max(maxt, curtime);
    }
    
    cout << maxt << endl;
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
