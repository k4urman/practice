#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t, n;
    cin >> t;


    while(t--){
        cin >> n;
        int odd(0), modzero(0), modtwo(0), maxfreq(0); 

        map<int, int> freq;
            
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;

            freq[a]++;
            maxfreq = max(maxfreq, freq[a]);

            if(a % 2 != 0){
                odd++;
            } else if (a % 4 == 0){
                modzero++;
            } else{
                modtwo++;
            }
        }
        int ret = max({odd, modzero, modtwo, maxfreq});
        cout << ret << endl;
    }
    return 0;


}
