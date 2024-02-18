from typing import List
from collections import Counter

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hash_set = Counter(nums)
        vals = [(i, hash_set[i]) for i in hash_set]
        vals.sort(key = lambda x: x[1], reverse=True)
        return vals[0][0]