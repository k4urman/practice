#include <iostream>

using namespace std;

int main() {
    int n, m, w(0), count(0);
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> m;
        count += m;
    }

    
    for (int i = 1; i <= 5; i++) {
        if ((count + i) % (n + 1) != 1) {
            w++;
        }
    }

    cout << w << endl;

    return 0;
}
