class Solution:
    def min_distance(self, word1: str, word2: str) -> int:
        len1 = len(word1)
        len2 = len(word2)

        dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

        for i in range(len1):
            dp[i][len2] = len1 - i
        for j in range(len2):
            dp[len1][j] = len2 - j

        for i in range(len1 - 1, -1, -1):
            for j in range(len2 - 1, -1, -1):
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    dp[i][j] = 1 + min(dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1])

        return dp[0][0]

# test cases
word1 = "kishan"
word2 = "gajera"

solution = Solution()
print(solution.min_distance(word1, word2))
