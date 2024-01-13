class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        new_word = ''
        min_len = min(len(word1), len(word2))

        for i in range(min_len):
            new_word += word1[i] + word2[i]

        if len(word1) == len(word2):
            return new_word
        elif len(word1) > min_len:
            new_word += word1[min_len:]
        else:
            new_word += word2[min_len:]
        
        return new_word

# driver code
tests = [
    ["abc", "pqr"],
    ["ab", "pqrs"],
    ["abcd", "pq"]
]

solution = Solution()

for test in tests:
    print(solution.mergeAlternately(test[0], test[1]))
