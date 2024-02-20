from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        h = len(nums) - 1
        while(l <= h):
            m = (l + h)//2
            if(nums[m] == target):
                return m
            elif(nums[m] > target):
                h = m - 1
            else:
                l = m + 1
        return -1  