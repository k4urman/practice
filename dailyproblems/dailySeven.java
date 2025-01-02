/*
Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121 Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

class Solution {
    public boolean isPalindrome(int x) {
        int originalNumber = x;
        int reversedNumber = 0;
        if(x < 0){
            return false;
        }else{
            while (x != 0) {
                int digit = x % 10;
                reversedNumber = reversedNumber * 10 + digit;
                x /= 10;
            }
        }
        return originalNumber == reversedNumber;
    }
}
