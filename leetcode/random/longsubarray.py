class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        r = 0

        seen = [0] * (max(nums) + 1)

        for i in range(n):
            if n - i <= r: 
                break
            A = [0, 0]
            
            for j in range(i, n):
                val = nums[j]
                if seen[val] != i + 1:
                    seen[val] = i + 1
                    A[val & 1] += 1

                if A[0] == A[1]:
                    r = max(r, j - i + 1)

        return r

