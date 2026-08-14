class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        hashm = {}
        count = 0
        left = 0

        for i, n in enumerate(s):
            if n in hashm and hashm[n] >= left: 
                left = hashm[n] + 1
            
            hashm[n] = i

            curr = i - left + 1
            count = max(count, curr)

        return count
        
