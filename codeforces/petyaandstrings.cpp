#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    transform(a.begin(), a.end(), a.begin(),
                   [](unsigned char c){ return tolower(c); });
    transform(b.begin(), b.end(), b.begin(),
                   [](unsigned char c){ return tolower(c); });

    if(a > b) {
        cout << "1" << endl;
    } else if (a < b) {
        cout << "-1" << endl;
    } else if (a == b) {
        cout << "0" << endl;
    }

    return 0;
}
