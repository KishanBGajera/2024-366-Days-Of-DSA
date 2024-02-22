from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            try:
                return nums[0]
            except:
                return

        res = 0
        for i in nums:
            res ^= i
        
        return res

        