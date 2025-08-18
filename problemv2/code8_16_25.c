/* Maximum 69 Number
You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:
Input: num = 9669
Output: 9969

Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:
Input: num = 9996
Output: 9999

Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:
Input: num = 9999
Output: 9999

Explanation: It is better not to apply any change.

Constraints:
    1 <= num <= 104
    num consists of only 6 and 9 digits
*/

#include <cmath>

bool isNine(int n){
    if(n == 0){
        return false;
    }
    while (n> 0) {
        if (n % 10 != 9) {
            return false;
        }
        n /= 10;
    }
    return true;
}

class Solution {
public:
    int maximum69Number (int num) {
        if(isNine(num)){
            return num;
        } else if(num > 1000 && num < 9000){
            return num + 3000;
        } else if((num > 100 && num < 900) || (num > 1000 && num < 9900)){
            return num + 300;
        } else if((num > 10 && num < 90) || (num > 100 && num < 990) || (num > 1000 && num < 9990)){
            return num + 30;
        } else if((num > 1 && num < 9) || (num > 10 && num < 99) || (num > 100 && num < 999) || (num > 1000 && num < 9999)){
            return num + 3;
        }
        return 0;
    }
};
