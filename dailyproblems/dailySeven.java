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
