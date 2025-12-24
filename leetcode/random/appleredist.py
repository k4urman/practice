class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:

        x = sum(apple)
        capacity.sort(reverse=True)
        result = 0
        while x > 0:
            x -= capacity[result]
            result += 1
        return result
        

        x = sum(apple)

        arr = [0] * 51
        high = 0
        low = 51
        for c in capacity:
            arr[c] += 1
            high = max(high, c)
            low = min(low, c)

        result = 0
        for i in range(high, low - 1, -1):
            while arr[i] > 0 and x > 0:
                x -= i
                arr[i] -= 1
                result += 1

        return result


        
        
