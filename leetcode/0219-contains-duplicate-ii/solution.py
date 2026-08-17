class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """

        seen = set()
        for i, n in enumerate(nums):
            if n in seen:
                return True
            seen.add(n)
            if len(seen) > k:
                seen.remove(nums[i-k])
        
        return False
        
