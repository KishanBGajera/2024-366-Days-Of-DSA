from typing import List

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        matrix = []
        for _ in range(n):
            matrix.append([0]*n)

        for edge in trust:
            matrix[edge[0] - 1][edge[1] - 1] = 1

        for i, node in enumerate(matrix):
            if sum(node) == 0:
                for x in range(n):
                    if x != i and matrix[x][i] == 0:
                        return -1
                return i + 1
        return -1