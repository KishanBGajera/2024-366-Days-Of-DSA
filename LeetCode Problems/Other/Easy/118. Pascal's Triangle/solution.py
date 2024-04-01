from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        out = []

        for i in range(0, numRows):
            out.append([0]*(i+1))
            out[i][0] = 1
            out[i][-1] = 1

            for j in range(1, i):
                out[i][j] = out[i-1][j-1] + out[i-1][j]

        return out
