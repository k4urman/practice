/*
A. Word Capitalization
time limit per test
2 seconds
memory limit per test
256 megabytes

Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.
Input

A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word will not exceed 103.
Output

ApPLe
ApPLe

konjac
Konjac
*/


// FINAL ATTEMPT - ACCEPTED
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
