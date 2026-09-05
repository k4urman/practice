#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;


    while(t--){
        cin >> n;
        vector<int> arr(n);
        vector<int> one;
        int fminus(-1), lminus(-1); // first minus and lats minus


        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i] == 1){
                one.push_back(i);
            } else if (arr[i] == -1){
                if (fminus == -1) {
                    fminus = i;
                }
                lminus = i;
            }
        }

        int maxlen(0), besti(-1), bestj(-1);
        int m = one.size();

        for (int x = 0; x <= m; x++){
            int l1 = (x == 0) ? -1 : one[x - 1];
            int r1 = (x == m) ? n : one[x];

            int mini = -1;
            if (l1 != -1) {
                mini = l1;
            } else {
                if (fminus != -1 && fminus < r1) {
                    mini = fminus;
                } else if (r1 < n){
                    mini = r1;
                }
            }

            int maxj = -1;
            if (r1 != n){
                maxj = r1;
            } else {
                if (lminus != -1 && lminus > l1){
                    maxj = lminus;
                } else if (l1 >= 0){
                    maxj = l1;
                }
            }


            if (mini != -1 && maxj != -1 && mini <= maxj){
                int len = maxj - mini +1;
                if (len > maxlen){
                    maxlen = len;
                    besti = mini;
                    bestj = maxj;
                }
            }


        }




        for (int z = 0; z < n; z++){
            if (arr[z] == -1){
                arr[z] = 0;
            }
        }
        if(maxlen > 0){
            arr[besti] = 1;
            arr[bestj] = 1;
        }

        for(int b = 0; b < n; b++){
            cout << arr[b] << (b == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;


}
