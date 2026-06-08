#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int s, n, x, y;
    cin >> s >> n;

    vector<pair<int, int>> dragons;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        dragons.emplace_back(x,y);
    }
    sort(dragons.begin(), dragons.end());

    for(const auto& [power, strength] : dragons) {
        if (s > power) {
            s += strength;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
