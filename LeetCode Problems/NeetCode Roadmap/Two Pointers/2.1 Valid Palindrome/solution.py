class Solution:
    def isPalindrome(self, s: str) -> bool:
        asciiln = "abcdefghijklmnopqrstuvwxyz0123456789"
        new_s = ""
        s = s.lower()

        for c in s:
            if c not in asciiln:
                print(c)
                continue
            new_s += c

        r = new_s
        r = "".join(list(r)[::-1])
        print(new_s)
        print(r)
        return r == new_s

# driver code

# tests = [
#     "A man, a plan, a canal: Panama",
#     "race a car",
#     "0P"
#     " "
# ]

# solution = Solution()

# for test in tests:
#     print(solution.isPalindrome(test))