#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int diff(abs(arr[0] - arr[n-1])), idx1(1), idx2(n);

    for(int i = 0; i < n-1; i++) {
        int d = abs(arr[i] - arr[i+1]);

        if (d < diff) {
            diff = d;
            idx1 = i + 1;
            idx2 = i + 2;
        }
    }

    cout << idx1 << " " << idx2 << endl;

    return 0;

}
