class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s or s == t:
            return True
        else:
            fast = 0
            slow = 0
            slen = len(s)
            tlen = len(t)
            while fast < tlen and slow < slen:
                if t[fast] == s[slow]:
                    slow += 1
                fast += 1
            return slow == slen