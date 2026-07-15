/*
Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
    public int reverse(int x) {
        boolean isNegative = x < 0;
        int num = Math.abs(x);
        int result = 0;

        while (num > 0) {
            int digit = num % 10;
            if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && digit > 7)) {
                return 0; 
            }
            result = result * 10 + digit;
            num /= 10;
        }
        return isNegative ? -result : result;

    }

}
