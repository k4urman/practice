#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int t = a + b + c;
        
        if (t%3 != 0) {
            cout << "NO\n";
            continue;
        }
        
        int tt = t/3;
        
        int down = 0, at = 0, up = 0;
        int diffb = 0, diffa = 0;
        
        for (int x : {a, b, c}) {
            if (x < tt) {
                down++;
                diffb = tt - x;
            } else if (x == tt) {
                at++;
            } else {
                up++;
                diffa = x - tt;
            }
        }
        
        if (down == 1 && up == 1 && at == 1 && diffb == 1 && diffa == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
