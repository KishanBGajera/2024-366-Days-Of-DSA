from typing import List

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)

        dp = [0]*n
        hold = -prices[0]
        
        for i in range(1, n):
            hold = max(hold, dp[i - 1] - prices[i])
            dp[i] = max(dp[i - 1], hold + prices[i] - fee)

        return dp[n - 1]
        