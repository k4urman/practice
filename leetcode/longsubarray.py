"""
3719. Longest Balanced Subarray I

You are given an integer array nums.
A is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
Return the length of the longest balanced subarray.

 

Example 1:
Input: nums = [2,5,4,3]
Output: 4
Explanation:
    The longest balanced subarray is [2, 5, 4, 3].
    It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.

Example 2:
Input: nums = [3,2,2,5,4]
Output: 5
Explanation:
    The longest balanced subarray is [3, 2, 2, 5, 4].
    It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.

Example 3:
Input: nums = [1,2,3,2]
Output: 3
Explanation:
    The longest balanced subarray is [2, 3, 2].
    It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.


Constraints:
    1 <= nums.length <= 1500
    1 <= nums[i] <= 105

"""

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        # size of the array nums
        n = len(nums)
        # the count of longest subarray
        r = 0

        # how many of the previous ones we've seen as an array of 0's, it is the largest value in nums + 1
        seen = [0] * (max(nums) + 1)
        # from index 0 to index n
        for i in range(n):
            # checks if we have already found the longest subarray
            if n - i <= r: 
                # breaks if so
                break

            # creates an array A, with two 0 values
            A = [0, 0]
            
            # for loop from i to n
            for j in range(i, n):
                #grabs whatever value is at nums[j]
                val = nums[j]

                # if whatever value in nums in seen is 0 then
                if seen[val] != i + 1:
                    # it makes the index i + 1, notifying that it was visted at THAT index
                    seen[val] = i + 1
                    # makes A's first value val and increments by 1
                    A[val & 1] += 1

                # sees if the two values are indeed equal
                if A[0] == A[1]:
                    # if they are equal, then we return the max
                    r = max(r, j - i + 1)

        # return the digit of the longest subarray
        return r


