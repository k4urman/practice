#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    
    long long nummone = 0;
    map<int, int> cnt;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == -1) {
            nummone++;
        } else {
            cnt[x]++;
        }
    }
    
    long long weven(0), wodd(0);
    if (nummone == 0) {
        weven = 1;
        wodd = 0;
    } else {
        weven = power(2, nummone - 1);
        wodd = weven;
    }
    
    long long P_0 = 1;
    for (auto const& [val, count] : cnt) {
        P_0 = (P_0 * power(2, count - 1)) % MOD;
    }
    
    long long cpairs = 0;
    for (auto const& [val, count] : cnt) {
        if (cnt.count(val + 1)) {
            cpairs++;
        }
    }

    long long ans = (weven * P_0) % MOD;
    long long ansodd = (wodd * cpairs) % MOD;
    ansodd = (ansodd * P_0) % MOD;
    
    ans = (ans + ansodd) % MOD;
    cout << ans << endl;
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
