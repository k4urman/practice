#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool need[26] = {false};
        
        for (int i = 0; i < n/2; i++){
            int x = s[i] - 'a';
            int y = s[n-i-1] - 'a';

            if (x == y){
                continue;
            }

            if (x > y){
                swap(x, y);
            }

            for (int j = x + 1; j <= y; j++) {
                need[j] = true;
            }
        }
        
        int a = 0;
        for (int i = 0; i < 26; i++) {
            if (need[i]){
                a++;
            }
        }
        
        cout << a << endl;
    }

    return 0;
}
