#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;

    string result = "";

    for (char c : s) {
        char lower = tolower(c);

        if (lower == 'a' || lower == 'o' || lower == 'y' || 
            lower == 'e' || lower == 'u' || lower == 'i') {
            continue; 
        } else {
            result += '.';
            result += lower;
        }
    }

    cout << result << endl;

    return 0;
}

