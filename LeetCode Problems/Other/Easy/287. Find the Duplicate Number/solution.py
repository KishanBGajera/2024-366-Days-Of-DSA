from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        look_up = set()
        for i in nums:
            if i not in look_up:
                look_up.add(i)
            else:
                return i
