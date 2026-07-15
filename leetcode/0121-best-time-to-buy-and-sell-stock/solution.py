class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        minm = 10001
        maxp = 0

        for p in prices:
            if p < minm:
                minm = p
            elif p - minm > maxp:
                maxp = p - minm
        
        return maxp
        
