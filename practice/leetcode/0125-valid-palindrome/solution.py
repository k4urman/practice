import string

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = ''
        for c in s:
            if c.isalnum():
                n += c.lower()
        return n == n[::-1]
        
