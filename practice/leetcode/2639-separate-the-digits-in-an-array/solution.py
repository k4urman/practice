class Solution(object):
    def separateDigits(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for item in nums:
            digits = [int(d) for d in str(item)]
            ans += digits
        return ans
        
