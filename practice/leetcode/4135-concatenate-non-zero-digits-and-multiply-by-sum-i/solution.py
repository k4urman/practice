class Solution(object):
    def sumAndMultiply(self, n):
        """
        :type n: int
        :rtype: int
        """

        digits = [d for d in str(n) if d != '0']
        
        if not digits:
            return 0

        x = int("".join(digits))
        ssum = sum(int(d) for d in digits)

        return x * ssum          
