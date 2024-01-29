class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s

        first_match = s != '' and (s[0] == p[0] or p[0] == '.')

        if len(p) > 1 and p[1] == '*':
            return self.isMatch(s, p[2:]) or (first_match and self.isMatch(s[1:], p))
        else:
            return first_match and self.isMatch(s[1:], p[1:])
        
# driver code

solution = Solution()

tests = [
    ["aa", "a"],  # False
    ["aa", "a*"], # True
    ["ab", ".*"]  # True
]

for test in tests:
    print(solution.isMatch(test[0], test[1]))
