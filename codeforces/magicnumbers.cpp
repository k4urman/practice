#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s = to_string(n);
    bool check = true;

    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] != '1' && s[i] != '4') {
            check = false;
        }
    }

    if (s[0] == '4') {
        check = false;
    }

    if (s.find("444") != s.npos) {
        check = false;
    }

    if (check == false) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;

}
