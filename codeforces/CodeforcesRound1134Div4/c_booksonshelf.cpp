#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> h(n);

        for (auto &x : h) {
            cin >> x;
        }
        
        sort(h.begin(), h.end());
        map<long long,int> cnt;

        for(auto x : h){
            cnt[x]++;
        }

        vector<long long> l,r,hide;

        for (auto &[val, c]:cnt) {

            l.push_back(val); 

            if (c >= 2) {
                r.push_back(val);

                for (int k = 0; k < c - 2; k++){
                    hide.push_back(val);
                }

            }

        }

        reverse(r.begin(), r.end());

        int m = (int)l.size() + (int)r.size();
        cout << m << endl;
        
        vector<long long> res;
        res.insert(res.end(), l.begin(), l.end());
        res.insert(res.end(), hide.begin(), hide.end());
        res.insert(res.end(), r.begin(), r.end());

        
        for(int v = 0; v < n; v++) {
            if (v) {
                cout << " ";
            }
            cout << res[v];
        }
        cout << endl;
    }
    return 0;
}
