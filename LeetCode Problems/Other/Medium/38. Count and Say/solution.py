class Solution:
    def encode(self, en: str) -> str:
        count = 1
        new_en = ''

        for i in range(len(en)):
            # when the characters aren't matching OR it is the last character of the sequence
            if i == len(en) - 1 or en[i] != en[i + 1]:
                new_en += str(count) + en[i]
                count = 1
            else:
                count += 1
        
        return new_en

    def countAndSay(self, n: int) -> str:
        dp = ['']*n
        dp[0] = '1'

        for i in range(1, n):
            dp[i] = self.encode(dp[i - 1])

        return dp[n - 1]
