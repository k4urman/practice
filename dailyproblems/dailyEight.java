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
