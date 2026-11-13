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
    
        int a = 0;
        int prev = 0;
        
        for (int i = 0; i < n; i++) {
            char na;
            int d;
            if (i % 2 == 0){
                na = 'R';
            }else{
                na='B';;
            }

            if(na != s[i]){ 
                d =1;
            } else{
                d = 0;
            }
            
            if (d != prev) {
                a++;
            }

            prev = d;
        }
        
        cout << a << endl;
    }
    
    return 0;
}
