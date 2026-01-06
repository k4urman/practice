
"""
FINAL ATTEMPT - ACCEPTED
"""
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
        

""" FIRST ATTEMPT
import string

class Solution(object):
    def isPalindrome(self, s):
        s = s.lower()
        f = "".join([char for char in s if char.isalpha()])
        r = f[::-1]
        return f == r
"""
