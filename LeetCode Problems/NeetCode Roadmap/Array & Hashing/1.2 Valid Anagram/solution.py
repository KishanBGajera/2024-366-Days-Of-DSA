class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        # if lengths of string aren't same they can't possibly be anagrams.
        if len(s) != len(t):
            return False

        s_hash = {}
        t_hash = {}
        
        # counts character occurrences of `s` string
        for c in s:
            if c in s_hash:
                s_hash[c] += 1
            else:
                s_hash[c] = 1

        # counts character occurrences of `t` string
        for c in t:
            if c in t_hash:
                t_hash[c] += 1
            else:
                t_hash[c] = 1

        return s_hash == t_hash
    
# driver code
    
# tests = [
#     ["anagram", "nagaram"], # true
#     ["rat", "car"] # false
# ]

# solution = Solution()

# for test in tests:
#     print(solution.isAnagram(test[0], test[1]))