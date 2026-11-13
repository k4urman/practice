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

        vector<vector<int>> r(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            r[u].push_back(v);
            r[v].push_back(u);
        }


        vector<int> p(n + 1, 0), order;
        p[1] = -1;
        vector<int> st; 
        st.push_back(1);

        while (!st.empty()) {

            int v = st.back(); st.pop_back();
            order.push_back(v);

            for (int u : r[v]) {
                if (u == p[v]){
                    continue;
                }

                if (p[u] != 0) {
                    continue;
                }

                p[u] = v;
                st.push_back(u);
            }
        }

        vector<long long> sz(n + 1, 1);
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int v = order[i];
            if (p[v] > 0) {
                sz[p[v]] += sz[v];
            }
        }

        vector<pair<long long,int>> ch;
        for (int u : r[1]) {
            if (u == p[1]) {
                continue;
            }

            ch.push_back({sz[u], u});
        }

        sort(ch.rbegin(), ch.rend());

        auto hang = [&](int c) -> long long {

            long long h = 0;
            int v = c;

            while (true) {
                long long mx1 = 0, mx2 = 0;
                int heavy = -1;

                for (int u : r[v]){
                    if (u == p[v]) {
                        continue;
                    }

                    long long s =sz[u];

                    if (s > mx1){ 
                        mx2 = mx1;
                        mx1 = s;
                        heavy = u;
                    }else if (s > mx2) {
                        mx2 = s; 
                    }


                }


                if (heavy ==-1){
                    break;
                }

                if (mx2 > h) {
                    h = mx2;
                }

                v = heavy;
            }
            return h;
        };

        long long r_ch;

        if ((int)ch.size() >= 2) {
            long long s3;

            if((int)ch.size()>=3) {
                s3 =ch[2].first;
            } else { 
                s3 = 0;
            }
            
            long long h1 = hang(ch[0].second);
            long long h2 = hang(ch[1].second);
            long long worst = max(max(s3, h1), h2);

            r_ch = (long long)n - worst;

        } else {
            long long h1 = hang(ch[0].second);
            r_ch = (long long)n - h1;
        }

        cout << r_ch << endl;
    }
    return 0;
}
