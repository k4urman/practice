#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count(0);
    cin >> n;
    vector<int> x(n), y(n);

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++) {
        bool r(false), l(false), u(false), d(false);

        for(int j = 0; j < n; j++){
            if (x[j] > x[i] && y[j] == y[i]) {
                r = true;
            } else if (x[j] < x[i] && y[j] == y[i]) {
                l = true;
            } else if (x[j] == x[i] && y[j] < y[i]) { 
                u = true;
            } else if (x[j] == x[i] && y[j] > y[i]) {
                d = true;
            }
        }
        if (r && l && u && d) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
