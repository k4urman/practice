class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        hashm = {}

        for i, n in enumerate(nums):
            if target - n in hashm:
                return i, hashm[target-n]
            else:
                hashm[n] = i
        
