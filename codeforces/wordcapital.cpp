#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    string s;
    cin >> s;
    s[0] = static_cast<string::value_type>(toupper(static_cast<unsigned char>(s[0])));
    cout << s << endl;
    return 0;
}
