from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0]*(n + 2)

        dp[1] = cost[0]

        for i in range(2, n + 1):
            dp[i] = cost[i - 1] + min(dp[i - 1], dp[i - 2])

        dp[-1] = min(dp[-2], dp[-3])
        return dp[-1]
