#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    long long curpsum = 0;
    bool possible = true;
    
    for (int i = 0; i < n; ++i) {
        curpsum += a[i];
        
        long long k = i + 1; 
        long long minreqsum = k * (k + 1) / 2;
        
        if (curpsum < minreqsum) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
