#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long v(0), p(0);
    cin >> n;
    
    vector<int> arr(100001);

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[x] = i;
    }

    int a;
    cin >> a;

    while(a--) {
        int q;
        cin >> q;
        
        v += arr[q];
        p += n - arr[q] + 1;
    }

    cout << v << " " << p << endl;

    return 0;

}
