#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t, n, k;
    cin >> t;
    string s;

    while(t--){
        cin >> n >> k;
        cin >> s;

        int nhoj = 0;
            
        for(int i = 0; i < n; i += k){
            bool onlyNhoj = true;

            for(int j = 0; j < k; j++){
                if (s[i + j] == '0'){
                    onlyNhoj = false;
                    break;
                }
            }

            if(onlyNhoj){
                nhoj++;
            }
        }

        cout << nhoj << endl;

    }

}
