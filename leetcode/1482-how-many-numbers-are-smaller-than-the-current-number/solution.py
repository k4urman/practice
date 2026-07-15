class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        res = []
        sortnums = sorted(nums)

        for i,n in enumerate(nums):
            res.append(sortnums.index(n))

        return res
        
