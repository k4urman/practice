#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len, lower(0), upper(0);
    len = s.length();

    for(int i = 0; i < len; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            lower++;
        } else{
            upper++;
        }
    }

    lower = len - lower;
    upper = len - upper;

    if((lower == upper) || (upper >= lower)){
        transform(s.begin(), s.end(), s.begin(), :: tolower);
    } else{
        transform(s.begin(), s.end(), s.begin(), :: toupper);
    }

    cout << s << endl;
    return 0;
}

/* FIRST ATTEMPT 
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len, lower(0), upper(0);
    len = s.length();

    for(int i = 0; i < len; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            lower++;
        } else{
            upper++;
        }
    }

    lower = len - lower;
    upper = len - upper;

    if(upper > lower){
        transform(s.begin(), s.end(), s.begin(), :: tolower);
    } else{
        transform(s.begin(), s.end(), s.begin(), :: toupper);
    }

    cout << s << endl;
    return 0;
}
*/
