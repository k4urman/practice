class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        numsdown = set(nums)

        if len(nums) != len(numsdown):
            return True
        
        return False
        
