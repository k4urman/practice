#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s, ans;

    cin >> n;

    while(n--) {
        cin >> s;
        if (s.length() <= 10) {
            cout << s << endl;
        } else {
            ans = s[0] + to_string(s.length() - 2) + s[s.length() - 1];
            cout << ans << endl;
        }
    }

    return 0;
}
