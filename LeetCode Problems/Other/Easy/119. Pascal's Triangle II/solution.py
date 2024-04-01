from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        out = []

        for i in range(0, rowIndex + 1):
            out.append([0]*(i+1))
            out[i][0] = 1
            out[i][-1] = 1

            for j in range(1, i):
                out[i][j] = out[i-1][j-1] + out[i-1][j]

        return out[-1] if out else []
