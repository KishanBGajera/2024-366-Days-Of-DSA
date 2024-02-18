from typing import List
from functools import reduce
import operator

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_copy = nums.copy()
        mult = reduce(operator.mul, nums)

        for i, e in enumerate(nums_copy):
            nums_copy[i] = int(mult/nums_copy[i]) if nums_copy[i] else reduce(operator.mul, nums[:i]+nums[i+1:])

        return nums_copy
