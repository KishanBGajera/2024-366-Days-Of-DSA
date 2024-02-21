from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = 0
        h = len(matrix) - 1

        while l <= h:
            m = (l + h) // 2
            if target <= matrix[m][-1] and target >= matrix[m][0]:
                lw = 0
                hw = len(matrix[m])
                while lw <= hw:
                    mw = (lw + hw)//2
                    if matrix[m][mw] == target:
                        return True
                    elif matrix[m][mw] > target:
                        hw = mw - 1
                    else:
                        lw = mw + 1
                return False
            elif matrix[m][-1] > target:
                h = m - 1
            else:
                l = m + 1
        
        return False
