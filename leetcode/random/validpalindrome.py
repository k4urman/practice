""" FIRST ATTEMPT
import string

class Solution(object):
    def isPalindrome(self, s):
        s = s.lower()
        f = "".join([char for char in s if char.isalpha()])
        r = f[::-1]
        return f == r
"""
