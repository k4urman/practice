class Solution(object):
    def sumAndMultiply(self, n):
        
        #grabs each value in n, making it a str, and makes sure it is not a 0
        digits = [d for d in range str(n) if d != '0']
        
        #edge case if all digits are 0
        if not digits:
            return 0

        #makes digits into an int with nothing in between ""
        x = int("".join(digits))

        #using each digit d in digits, sum them together
        ssum = sum(int(d) for d in digits)

        return x * ssum
