"""
3074. Apple Redistribution into Boxes

You are given an array apple of size n and an array capacity of size m.
There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
Note that, apples from the same pack can be distributed into different boxes.

 

Example 1:
Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.

Example 2:
Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.

 

Constraints:

    1 <= n == apple.length <= 50
    1 <= m == capacity.length <= 50
    1 <= apple[i], capacity[i] <= 50
    The input is generated such that it's possible to redistribute packs of apples into boxes.

"""

class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:

        # first solution
        x = sum(apple) # find the sum of all the values in array apple
        capacity.sort(reverse=True) # sort it by lowest to largest
        result = 0 # this is the number of baskets needed
        while x > 0: # for each value in the sum, we subtract the index value of the sorted array
            x -= capacity[result]
            result += 1
        return result # return logorithmic time O(n + m log(m)
        
        # second solution - counting sort
        x = sum(apple) # sum of all the values in apple

        arr = [0] * 51 # make an array from index 0 to 50 with all 0's
        high = 0 
        low = 51
        
        # for every value in capacity, if we find a match, we count 1 for it in the arr array
        # we also change the high and low to find the range
        for c in capacity: 
            arr[c] += 1
            high = max(high, c)
            low = min(low, c)

        result = 0 # number of baskets needed

        # from the highest value in the range capacity to the lowest, we go down by 1
        # for each counted number we keep looping and -1 the total sum x and the count value for the number
        # we add it all into the result and return
        for i in range(high, low - 1, -1):
            while arr[i] > 0 and x > 0:
                x -= i
                arr[i] -= 1
                result += 1

        return result


        
        
