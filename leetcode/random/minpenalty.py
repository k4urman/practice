

class Solution:
    def bestClosingTime(self, customers: str) -> int:
        best = 0
        p = 0
        pre = 0

        for i in range(len(customers)):
            if customers[i] == 'Y':
                pre += -1
            else:
                pre += 1
            
            if pre < p:
                best = i + 1
                p = pre
        
        return best
