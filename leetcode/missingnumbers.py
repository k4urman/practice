class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        newarr = sorted(nums)
        n = 0

        for i in range(len(newarr)):
            if i == newarr[i]:
                continue
            else:
                return i
            n = i

        return len(nums)

        
