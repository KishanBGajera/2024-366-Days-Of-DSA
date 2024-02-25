from typing import List

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s_hash = dict()
        t_hash = dict()
        for c in s:
            if c in s_hash:
                s_hash[c] += 1
            else:
                s_hash[c] = 1
        for c in t:
            if c in t_hash:
                t_hash[c] += 1
            else:
                t_hash[c] = 1
        return s_hash == t_hash
  
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strslen = len(strs)
        if strslen < 2:
            return [strs]

        anagrams = []
        len_anagrams = 0

        for str in strs:
            if len_anagrams == 0:
                anagrams.append([str])
                len_anagrams += 1
            else:
                count = len_anagrams
                for anagram in anagrams:
                    if self.isAnagram(str, anagram[0]):
                        anagram.append(str)
                    else:
                        count -= 1
                if count == 0:
                    anagrams.append([str])
                    len_anagrams += 1

        return anagrams
        