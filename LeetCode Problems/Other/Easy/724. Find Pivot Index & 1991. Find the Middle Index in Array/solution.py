from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        for i, e in enumerate(nums):
            if sum(nums[:i]) == sum(nums[i+1:]):
                return i
        return -1