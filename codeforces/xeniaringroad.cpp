#include <iostream>

using namespace std;

int main() {
    int n, m, x, pos(1),count(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        if (x >= pos) {
            count += x - pos;
        } else {
            count += (n-pos) + x; 
        }
        pos = x;
    }

    cout << count << endl;
    return 0;
}
