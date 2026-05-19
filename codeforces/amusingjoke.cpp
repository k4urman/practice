#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b, c;
    vector<int> seen(256, 0);

    cin >> a >> b >> c;

    string d = a + b;
    for(char x : d){
        seen[x]++;
    }

    if(d.length() != c.length()) {
        cout << "NO" << endl;
        return 0;
    }

    for (char x : c) {
        if(seen[x] > 0) {
            seen[x]--;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

