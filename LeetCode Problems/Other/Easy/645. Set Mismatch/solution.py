from typing import List
from collections import Counter

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        lookup = dict(Counter(nums))
        l = len(nums)
        dupe = None
        for key in lookup:
            if lookup[key] == 2:
                dupe = key
        return [dupe, int(l*(l+1)/2) - sum(nums) + dupe]
