#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    int count(0);

    cin >> s;
    
    vector<bool> seen(256, false);

    for(char c: s){
        if(!seen[c]) {
            count++;
            seen[c] = true;
        }
    }

    if (count % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;

}
